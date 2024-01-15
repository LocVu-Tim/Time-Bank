#include "string"
#include "iostream"

class User;

class Rating {

private:
    //Attribute
    int ratingID;
    int userID;
    int raterID;
    std::string type;
    double ratingValue;
    std::string comment;

public:
    //Default construct or
    Rating() {};

    //Constructor
    Rating(int ratingId, int userId, int raterId, std::string &type, double ratingValue,
           std::string &comment)
            : ratingID(ratingId), userID(userId), raterID(raterId), type(type), ratingValue(ratingValue),
              comment(comment) {}

    //1. Method to get rating ID
    int getRatingID();

    //2. Method to get user ID
    int getUserID();

    //3. Method to get rater ID
    int getRaterID();

    //4. Method to get rating type
    std::string getRatingType();

    //5. Method to get rating value
    double getRatingValue();

    //6. Method to get comment
    std::string getComment();

    //7. Method to set rating ID
    void setRatingID(int ID);

    //8. Method to set user ID
    void setUserID(int ID);

    //9. Method to set rater ID
    void setRaterID(int ID);

    //10. Method to set rating type
    void setRatingType(int rType);

    //11. Method to set rating value
    void setRatingValue(double value);

    //12. Method to set comment
    void setComment(std::string rComment);
};