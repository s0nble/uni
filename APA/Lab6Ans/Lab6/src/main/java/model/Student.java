package model;

public class Student {

    private String name;
    private double midterm;
    private double fin;

    public Student(String name, double midterm, double fin) {
        this.name = name;
        this.midterm = midterm;
        this.fin = fin;
    }

    public String getName() {
        return name;
    }

    public double calculateGrade() {
        return midterm * 0.6 + fin * 0.4;
    }

    public String getStatus() {

        if (calculateGrade() >= 50)
            return "PASS";
        else
            return "FAIL";
    }

    public boolean hasInvalidValues() {

        if (midterm < 0 || fin < 0)
            return true;

        return false;
    }
}