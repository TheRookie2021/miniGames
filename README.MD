# This repo contains some mini games
### Arithmatic game(C++): 
- a simple game that trains your basic calculation skill in terminal  
    - features: record info like correcte rate and reaction time
        - level 1: two variables/one-one digit  - add/minus/multiply
        - level 2: two variables/one-two digit  - add/minus/multiply
        - level 3: two variables/two-two digit  - add/minus/multiply
        - level 4: three variables/one-one-one digit    - add/minus/multiply
        - level 5: three variables/one-one-two digit    - add/minus/multiply
        - level 6: three variables/one-two-two digit    - add/minus/multiply
        - level 7: three variables/two-two-two digit    - add/minus/multiply
    - about level design, there are somthing to reconsider(if i have time to reconstruct this app):
        - 70+80 is two two, but it's relatively easier than 87+49 (or maybe is as easy as 8+7)
        - the more carries an arithmatic contains, the more mental memory the subject need to use to retain each carry
    - next update:
        - use header file
        - handling exception of cin<<enter, stoi(enter)
        - let level be a variable varies according to the current correct rate(staircase method)
### English Typing practice
- practicing English typing as fast and correct as possible!
    - feature: record time and correctness  
    - futher: 
        - analysis which part of the typing can be mistake easily
        - record which part of the work(typing) is relatively slower