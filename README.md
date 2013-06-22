#uva-solutions

My solutions to some [UVA OJ](http://uva.onlinejudge.org/) problems 

My uHunt profile [http://uhunt.felix-halim.net/id/81832](http://uhunt.felix-halim.net/id/81832)

##Problems source

Most problems I am solving - are recommended ones in the [Competitive Programming book by Steven & Felix Halim](https://sites.google.com/site/stevenhalim/) As I am studying this book, the new problems get solved and added.

##Convenience toolset

There are several convenience tools that I use
###run.sh 
script for compiling the solution, running against the test data set and comparing (using diff) with the designated output

###new.sh
script for starting work on a new solution to the specified problem - this:

* creates the working directory for the solution 
* copies the template code
* downloads the problem description pdf 
* opens the problem description in the browser
* allows to paste the input.txt and output.txt files
* as a last step it opens the source code in Sublime Text 2

###download.py
script for downloading pdf description of the problem

###submit.py
script for submitting a solution to UVa OJ, without the need to do it via the form in the browser

###open.py
script for opening the problem url in the browser (the urls were previously scraped by crawler.py, scraping was needed - since there is no well defined mapping of the problem id to problem url)