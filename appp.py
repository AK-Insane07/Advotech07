import subprocess
from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

# Function to call the C++ program with user input
def call_cpp_program(user_input):
    try:
        result = subprocess.run(['my_cpp_program.exe', user_input],
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                text=True,
                                shell=True)  # Use shell=True on Windows
        return result.stdout
    except Exception as e:
        return str(e)

@app.route("/", methods=["GET", "POST"])
def input_page():
    if request.method == "POST":
        user_input = request.form.get("user_input")
        # Call the C++ program with the user input
        cpp_output = call_cpp_program(user_input)
        return render_template("output.html", cpp_output=cpp_output)
    return render_template("input.html")

if __name__ == '__main__':
    app.run(debug=True)
