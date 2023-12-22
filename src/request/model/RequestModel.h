#ifndef REQUEST_MODEL_H
#define REQUEST_MODEL_H

// dữ liệu ở đây là dữ liệu của request
// cần pha

class RequestModel
{
public:
    RequestModel();
    ~RequestModel();

    // Load data from file
    void load();

    // CRUD functions
    void createRequest();
    void readRequest();
    void updateRequest();
    void deleteRequest();

private:
    // Add your member variables here
};

#endif // REQUEST_MODEL_H
