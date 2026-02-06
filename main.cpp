#include <string>
#include <iostream>
#include <fstream>

class user
{
public:
    user(std::string username, std::string email, std::string password)
        : username(username), email(email), password(password) {}

    std::string get_username() const
    {
        return username;
    }

    std::string get_email() const
    {
        return email;
    }

    std::string get_password() const
    {
        return password;
    }

    std::ofstream save_to_file(const std::string &filename) const
    {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open())
        {
            file << "Username: " << username << "\n";
            file << "Email: " << email << "\n";
            file << "Password: " << password << "\n";
            file << "--------------------------\n";
            file.close();
        }
        else
        {
            std::cerr << "Unable to open file for writing: " << filename << "\n";
        }

        return file;
    }

private:
    std::string username;
    std::string email;
    std::string password;
};

int new_user_add()
{

    std::cout << "Enter username: ";
    std::string username;
    std::cin >> username;
    std::cout << "Enter email: ";
    std::string email;
    std::cin >> email;
    std::cout << "Enter password: ";
    std::string password;
    std::cin >> password;


    user new_user(username, email, password);
    std::cout << "New user created:\n";
    std::cout << "Username: " << new_user.get_username() << "\n";
    std::cout << "Email: " << new_user.get_email() << "\n";
    std::cout << "Password: " << new_user.get_password() << "\n";

    user user_to_save(username, email, password);
    user_to_save.save_to_file("users.txt");

    std::cout << "User information saved to users.txt\n";
    std::cout << "Do you want to add another user? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        new_user_add();
    }
    else
    {
        std::cout << "Exiting the program.\n";
    }

    return 0;
}

int main()
{
    
    new_user_add();


    

    return 0;
}
