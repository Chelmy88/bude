library(shiny)

# Define server logic required to generate and plot a random distribution
shinyServer(function(input, output) {

  # Expression that generates a plot of the distribution. The expression
  # is wrapped in a call to renderPlot to indicate that:
  #
  #  1) It is "reactive" and therefore should be automatically
  #     re-executed when inputs change
  #  2) Its output type is a plot
  #
  #
  #
  data <- read.csv('/data/data.txt', sep=" ")
  data[,1] <- as.POSIXct(data[,1],format="%Y%m%d-%H%M")
  nlines <- system(sprintf("wc -l %s",'/data/data.txt'),intern=TRUE)
  nlines <- strtoi(strsplit(nlines," ")[[1]][1])
  last <- read.csv('/data/data.txt', sep=" ", skip=nlines-2)
  data <- reactiveValues(data = data, last = NULL)
  #rm(data)

  getData <- function(){
    data <- read.csv('/data/data.txt', sep=" ")
    data[,1] <- as.POSIXct(data[,1],format="%Y%m%d-%H%M")
    return(data)
  }

  observeEvent(input$day, {
    data$data <- getData()
    write.table(data$data, stderr(), append=TRUE)
  })

  observeEvent(input$week, {
    data$data <-  getData()
    data$data[,c(2,3,4,5)]=data$data[,c(2,3,4,5)]-1
  })

  observeEvent(input$year, {
    data$data <-  getData()
    data$data[,c(2,3,4,5)]=data$data[,c(2,3,4,5)]/2
  })


  output$distPlot <- renderPlot({
    plot(data$data[,c(1,2)],type="l",ylim=c(0,20),  main=paste(last, collapse = " ", sep = " "))
    lines(data$data[,c(1,3)],type="l", col=2)
    lines(data$data[,c(1,4)],type="l", col=3)
    lines(data$data[,c(1,5)],type="l", col=4)
  })

  output$textWithNewlines <-  renderText({
    len <- length(data$data[,1])
    return(paste(data$data[len,], collapse  = " "))
  })


})


