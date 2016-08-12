
# fun #

readAndRun <- function(fileName, inits, steps) {
    nodeData <- read.table(fileName, sep="\t", stringsAsFactors=F, header=F)
    res0 <- runNet(nodeData[,1], inits, steps)
    res0
}


fileToEdgelist <- function(fileName) {
    nodeData <- read.table(fileName, sep="\t", stringsAsFactors=F, header=F)
}


listToEdgeList <- function(res0) {
    # takes the result from readAndRun, and returns an edgelist of states
    l <- lapply(1:length(res0), function(i) {
        data.frame(From=res0[[i]][1:(length(res0[[i]])-1)],
                     To=res0[[i]][2:(length(res0[[i]]))])})
    unique(do.call(rbind, l))
}


plotEdgeList <- function(es) {
    require(igraph)
    g <- graph.edgelist(as.matrix(es))
    plot(g, vertex.size=05, vertex.label.cex=0.2)
}
