#include "rating.h"

#include <utility>

Rating::Rating(int ratingId, int userId, int raterId, std::string type, double ratingValue, std::string comment)
        : ratingID(ratingId), userID(userId), raterID(raterId), type(std::move(type)), ratingValue(ratingValue),
          comment(std::move(comment)) {}

//1. Method to get rating ID
int Rating::getRatingID() const {
    return this->ratingID;
}

//2. Method to get user ID
int Rating::getUserID() const {
    return this->userID;
}

//3. Method to get rater ID
int Rating::getRaterID() const {
    return this->raterID;
}

//4. Method to get rating type
std::string Rating::getRatingType() {
    return this->type;
}

//5. Method to get rating type as a number
int Rating::getRatingTypeNumb() {
    if (this->type == "skill") {
        return 1;
    } else if (this->type == "supporter") {
        return 2;
    } else if (this->type == "host") {
        return 3;
    }
    return 0;
}

//6. Method to get rating value
double Rating::getRatingValue() const {
    return this->ratingValue;
}

//7. Method to get comment
std::string Rating::getComment() {
    return this->comment;
}

//8. Set rating ID
void Rating::setRatingID(int ID) {
    this->ratingID = ID;
}

//9. Method to set user IO
void Rating::setUserID(int ID) {
    this->userID = ID;
}

//10. Method to set rater ID
void Rating::setRaterID(int ID) {
    this->raterID = ID;
}

//11. Method to set rating type
void Rating::setRatingType(int rType) {
    if (rType == 1) {
        this->type = "skill";
    } else if (rType == 2) {
        this->type = "supporter";
    } else if (rType == 3) {
        this->type = "host";
    }
}

//12. Method to set rating value
void Rating::setRatingValue(double value) {
    this->ratingValue = value;
}

//13. Method to set comment
void Rating::setComment(std::string rComment) {
    this->comment = std::move(rComment);
}

//14. Method to show rating info
void Rating::showRatingInfo() {
    std::cout << "Rating ID: " << this->ratingID << std::endl
        << "User ID: " << this->userID << std::endl
        << "Author ID: " << this->raterID << std::endl
        << "Type: " << this->type << std::endl
        << "Score: " << this->ratingValue << std::endl
        << "Comment: " << this->comment << std::endl << "\n";
};
