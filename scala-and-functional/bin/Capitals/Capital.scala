object Capitals {
    def main(args: Array[String]) {
        var capital = Map("US" -> "Washington", "France" -> "Paris")
        capital += ("Japan" -> "Tokyo")
        println(capital("France"))
    }
}

