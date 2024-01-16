#include "rating.h"

//1. Method to get rating ID
int Rating::getRatingID() {
    return this->ratingID;
}

//2. Method to get user ID
int Rating::getUserID() {
    return this->userID;
}

//3. Method to get rater ID
int Rating::getRaterID() {
    return this->raterID;
}

//4. Method to get rating type
std::string Rating::getRatingType() {
    return this->type;
}

//5. Method to get rating value
double Rating::getRatingValue() {
    return this->ratingValue;
}

//6. Method to get comment
std::string Rating::getComment() {
    return this->comment;
}

//7. Set rating ID
void Rating::setRatingID(int ID) {
    this->ratingID = ID;
}

//8. Method to set user IO
void Rating::setUserID(int ID) {
    this->userID = ID;
}

//9. Method to set rater ID
void Rating::setRaterID(int ID) {
    this->raterID = ID;
}

//10. Method to set rating type
void Rating::setRatingType(int rType) {
    if (rType == 1) {
        this->type = "skill";
    } else if (rType == 2) {
        this->type = "supporter";
    } else if (rType == 3) {
        this->type = "host";
    } else {
        std::cout << "Invalid choice!";
    }
}

//11. Method to set rating value
void Rating::setRatingValue(double value) {
    this->ratingValue = value;
}

//12. Method to set comment
void Rating::setComment(std::string rComment) {
    this->comment = rComment;
}