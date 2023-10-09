import subprocess
from flask import Flask, render_template, request, jsonify

app = Flask(__name__)


# Function to call the C++ program with user input
def call_cpp_program(user_input):
    try:
        # Replace 'path_to_executable' with the actual path to your C++ executable
        result = subprocess.run(
            ['path_to_executable\\C:\\Users\\ASUS\\.vscode\\AI-ATTORNEY\\my_cpp_program.exe', user_input],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            shell=True)  # Use shell=True on Windows
        return result.stdout
    except Exception as e:
        return str(e)


@app.route('/process_query', methods=['POST'])
def process_query():
    query = request.json.get('query')

    # Call the C++ program with the query
    result = call_cpp_program(query)

    return jsonify(result=result)


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        query = request.form.get("query")
        # Call the C++ program with the user input
        cpp_output = call_cpp_program(query)
        return render_template("gyaSUBMIT.html", query=query, cpp_output=cpp_output)
    return render_template("page2.html")


if __name__ == '__main__':
    app.run(debug=True)
