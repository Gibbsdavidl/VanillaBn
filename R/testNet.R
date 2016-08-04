
# test

testRun <- function(nodeData, runs, steps) {
    nodeData <- c("A ; B ; B", "B ; A,C ; A*C", "C ; A ; 1-A")
    runs <- 3
    steps <- 10
    res0 <- runNet(nodeData, runs, steps)
    res0
}
