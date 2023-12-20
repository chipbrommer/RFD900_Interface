///////////////////////////////////////////////////////////////////////////////
//! @file		rfd900_io.h
//! @brief		RFD900 IO class
//! @author		Chip Brommer
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Includes:
//          name                        reason included
//          --------------------        ---------------------------------------
#include    <mutex>                     // data protection
#include    <fstream>                   // file output
#include    <cstdint>                   // standard integers
#include    <thread>                    // thread sleep
#include    <iostream>                  // io
//
///////////////////////////////////////////////////////////////////////////////

class Rfd900
{
public:
    /// @brief Default constructor
    Rfd900();

    /// @brief Default deconstructor
    ~Rfd900();

    /// @brief Initialze the RFD900 radio and this interface
    void    Initialize();

    /// @brief Start the Rfd900 interface - THIS IS A BLOCKING FUNCTION 
    void    Start();

    /// @brief Stop the Rfd900 interface
    void    Stop();

    /// @brief Reset the Rfd900 interface
    void    Reset();

    /// @brief Sends a message over the RFD900
    /// @return -1 on error
    int     Write(std::uint8_t* buffer);

    /// @brief Read any data on the RFD900
    /// @return -1 on error
    int     Read(std::uint8_t& buffer);
protected:
private:
    /// @brief Configure the RFD900 radio
    /// @return -1 on error
    int     ConfigureRadio();
};

