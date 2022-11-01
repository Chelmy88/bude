library(shiny)

# Define UI for application that plots random distributions
shinyUI(fluidPage(

  # Application title
  titlePanel("Ferme de Budé"),

  # Sidebar with a slider input for number of observations
  sidebarLayout(
    sidebarPanel(
      actionButton("day", "Jour"),
      actionButton("week", "Semaine"),
      actionButton("month", "Mois"),
      actionButton("year", "Année")
    ),


    # Show a plot of the generated distribution
    mainPanel(
      plotOutput("distPlot"),
      textOutput('textWithNewlines') # text with newline characters outpu
    )
  )
))


