/* Hospital
 *
 * Desc:
 * This program allows the user to upload and remove information about
 * the hospitals staff members, patients, care periods, medications assigned,
 * and various information of the aforementioned groups. The user is able to
 * browse the data that he has managed into the system and print them in a clear
 * format.
 * Commands user by the program include (but also have acronyms):
 * QUIT, HELP, READ_FROM, SET_DATE, ADVANCE_DATE, RECRUIT, PRINT_ALL_STAFF
 * ADD_MEDICINE, REMOVE_MEDICINE, ENTER, LEAVE, ASSIGN_STAFF, PRINT_PATIENT_INFO,
 * PRINT_PATIENT_INFO, PRINT_CARE_PERIODS, PRINT_ALL_MEDICINES, PRINT_ALL_PATIENTS
 * AND PRINT_CURRENT_PATIENTS.
 *
 * Program author:
 *
 * Name: Antton Alivuotila
 * Student number: 151259218
 * UserID: bvanal
 * E-Mail: antton.alivuotila@tuni.fi
 */

#include "cli.hh"
#include "hospital.hh"
#include <string>

const std::string PROMPT = "Hosp> ";


int main()
{
    Hospital* hospital = new Hospital();
    Cli cli(hospital, PROMPT);
    while ( cli.exec() ){}

    delete hospital;
    return EXIT_SUCCESS;
}
