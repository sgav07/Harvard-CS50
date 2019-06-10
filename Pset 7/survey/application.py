import cs50
import csv


from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


# app_route to check if each field is populated and write the provided info into the csv file
@app.route("/form", methods=["POST"])
def post_form():
    if not request.form.get("name") or not request.form.get("email") or not request.form.get("brand") or not request.form.get("vehicle"):
        return render_template("error.html", message="Error. Please make sure you have populated all of the fields")
    file = open("survey.csv", "a")
    writer = csv.writer(file)
    writer.writerow((request.form.get("name"), request.form.get("email"), request.form.get("brand"), request.form.get("vehicle")))
    file.close()
    return redirect("/sheet")


# app_route to read the csv file and load it into list. Then the template is rendered
@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as file:
        reader = csv.reader(file)
        customers = list(reader)
    return render_template("sheet.html", customers=customers)

