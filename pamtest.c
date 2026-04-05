#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <stdio.h>
static struct pam_conv conv = { misc_conv, NULL };

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: pamtest <pam_config> <username>\n");
    }

    pam_handle_t *pamh;
    int r;

    if ((r = pam_start(argv[1], argv[2], &conv, &pamh)) != PAM_SUCCESS) {
        fprintf(stderr, "Start failed: %d\n", r);
    }
    else if ((r = pam_authenticate(pamh, 0)) != PAM_SUCCESS) {
        fprintf(stderr, "Authentication failed: %d\n", r);
    }
    else if ((r = pam_acct_mgmt(pamh, 0)) != PAM_SUCCESS) {
        fprintf(stderr, "Account management failed: %d\n", r);
    }
    else if ((r = pam_end(pamh, r)) != PAM_SUCCESS) {
        fprintf(stderr, "End failed: %d\n", r);
    }
    else {
        fprintf(stdout, "Success.\n");
    }
}
