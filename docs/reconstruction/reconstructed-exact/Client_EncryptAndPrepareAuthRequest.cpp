// READABILITY (auto CF):
//  - Body size: ~143 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, return×2, for×1.
//  - Notable callees: CONCAT22×4, FUN_0076cec0×3, FUN_0067b110×2, DES_EncryptBlock8, FUN_0046e280, FUN_0046ebf0, FUN_0067ba30, FUN_0071e420.
//  - Strings: "Login"; "AuthServer"; "Invalid name or password"; "Password string too long".
//  - Return sites: 2.

// =============================================================================
// Client_EncryptAndPrepareAuthRequest
// -----------------------------------------------------------------------------
// Purpose:  Build EMSG_Login_Request credentials: validate username/password
//           lengths, pack into a 30-byte buffer, DES-ECB encrypt first 24 bytes
//           (3× 8-byte blocks) with key "NETD\0\0\0\0", then attach optional
//           fields and hand off to the auth client send path.
//
// Address:  0x00728e50  (autoassault.exe, image base 0x400000)
// Stable:   aa_00728e50
// System:   auth-login (named inventory tagged missions-progression by heuristic)
// Source:   palantir\infrastruct\Auth\authClientLib\AuthClientImpl.cpp
//
// Parameters (decompiler-derived; thiscall-ish via auth client object):
//   pAuthClient  this / auth client instance
//   pszUsername  C-string username (max 14 chars, exclusive of NUL)
//   pszPassword  C-string password (max 16 chars, exclusive of NUL)
//   param4       copied to request+0x30 (unknown semantic - Tentative)
//   param5       low 16 bits copied to request+0x34; also reused as err out
//
// Returns:  0 on success, 0xFFFFFFFF on validation/log failure.
//
// Encryption detail (plate / body):
//   - Credentials buffer: 14-byte username (strncpy) + 16-byte password memcpy
//   - DES_EncryptBlock8 applied three times over words 0..5 (24 bytes)
//   - Last 6 bytes of the 16-byte password region are NOT encrypted
//   - DES key setup is elsewhere (DES_InitializeCipher path; key "NETD...")
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cstring>

// SEH / MSVC frame (not reconstructed as live exception machinery)
extern void* ExceptionList;

// Callees
void  FUN_0046e280(void* pScratch);                 // path when socket slot empty
void  FUN_0067ba30(void* pScratch);                 // path when socket present
void  FUN_00727c00(const char* a, const char* b);   // "Login","AuthServer" scope
void  FUN_0067b110(void);                           // destroy/cleanup scratch
void* FUN_0076cec0(int* pOut, const char* msg);     // format log string
void  vog_LogMessage(const char* file, std::uint32_t line,
                     int level, void* msg);
void* operator_new(std::size_t);
int   FUN_0071e420(void);                           // AuthRequest ctor (0x38 bytes)
void  DES_EncryptBlock8(void* pBlock8);             // 0x0071c1b0
void  FUN_0046ebf0(void);                           // enqueue / send prepared request

// Auth request object layout (fields written here)
static constexpr std::uintptr_t kOffCred0   = 0x10; // first 4 of encrypted creds
static constexpr std::uintptr_t kOffCred4   = 0x14;
static constexpr std::uintptr_t kOffCred8   = 0x18;
static constexpr std::uintptr_t kOffCred12  = 0x1c; // u16 then overlapping u32 writes
static constexpr std::uintptr_t kOffParam4  = 0x30;
static constexpr std::uintptr_t kOffParam5  = 0x34; // u16
static constexpr std::uintptr_t kOffSockPtr = 0x30; // on auth client (param_1+0x30)

// Log line numbers in AuthClientImpl.cpp (from decompile immediates)
static constexpr std::uint32_t kLineInvalidCreds = 0xc4; // 196
static constexpr std::uint32_t kLineUserTooLong  = 0xcb; // 203
static constexpr std::uint32_t kLinePassTooLong  = 0xd2; // 210

std::uint32_t Client_EncryptAndPrepareAuthRequest(
    int pAuthClient,
    char* pszUsername,
    char* pszPassword,
    std::uint32_t param4,
    int param5)
{
    char* pScan;
    char  ch;
    bool  useEmptySocketPath;
    bool  useLiveSocketPath;
    void* pMsg;
    void* pAlloc;
    int   pRequest = 0;
    std::uint32_t logLine;
    std::uint32_t* pBlock;

    // 30-byte credentials staging (username 14 + password 16); zeroed then filled.
    // Layout matches decompiler locals local_2c .. local_10 (15× u16 / 30 bytes).
    std::uint8_t creds[30];
    std::uint8_t scratchA[16];
    std::uint8_t scratchB[16];

    // SEH frame setup omitted (LAB_009af56c / ExceptionList).

    // Branch on auth client socket slot at +0x30: null or *slot == -1 → empty path.
    int** ppSock = *reinterpret_cast<int***>(pAuthClient + static_cast<int>(kOffSockPtr));
    // Note: decompiler compares *(int**)(param_1+0x30) and ** of that.
    if (*reinterpret_cast<int**>(pAuthClient + 0x30) == nullptr ||
        **reinterpret_cast<int**>(pAuthClient + 0x30) == -1) {
        FUN_0046e280(scratchA);
        useLiveSocketPath = false;
        useEmptySocketPath = true;
    } else {
        FUN_0067ba30(scratchB);
        useLiveSocketPath = true;
        useEmptySocketPath = false;
    }

    FUN_00727c00("Login", "AuthServer");
    if (useEmptySocketPath) {
        FUN_0067b110();
    }
    if (useLiveSocketPath) {
        FUN_0067b110();
    }

    // Validate non-empty username and password.
    if (pszUsername == nullptr || *pszUsername == '\0' ||
        pszPassword == nullptr || *pszPassword == '\0') {
        pMsg = FUN_0076cec0(&param5, "Invalid name or password");
        logLine = kLineInvalidCreds;
    } else {
        // strlen(username) must be < 0x0F (15).
        pScan = pszUsername;
        do {
            ch = *pScan;
            pScan++;
        } while (ch != '\0');
        if (static_cast<int>(pScan - (pszUsername + 1)) < 0x0f) {
            // strlen(password) must be < 0x11 (17).
            pScan = pszPassword;
            do {
                ch = *pScan;
                pScan++;
            } while (ch != '\0');
            if (static_cast<int>(pScan - (pszPassword + 1)) < 0x11) {
                pAlloc = operator_new(0x38);
                if (pAlloc != nullptr) {
                    pRequest = FUN_0071e420(); // constructs AuthRequest in allocated storage
                }

                std::memset(creds, 0, sizeof(creds));
                // Username: first 14 bytes of creds.
                std::strncpy(reinterpret_cast<char*>(creds), pszUsername, 0x0e);
                // Password: next 16 bytes (creds+14). Decompiler packs via u16/u32 splits;
                // behavior is a 16-byte memcpy of the password string bytes.
                std::memcpy(creds + 14, pszPassword, 16);

                // DES-ECB encrypt three 8-byte blocks (bytes 0..23 only).
                pBlock = reinterpret_cast<std::uint32_t*>(creds);
                for (int i = 0; i < 3; ++i) {
                    DES_EncryptBlock8(pBlock);
                    pBlock += 2; // advance 8 bytes
                }

                // Write encrypted credentials + trailing fields into AuthRequest.
                *reinterpret_cast<std::uint32_t*>(pRequest + 0x10) =
                    *reinterpret_cast<std::uint32_t*>(creds + 0);
                *reinterpret_cast<std::uint32_t*>(pRequest + 0x14) =
                    *reinterpret_cast<std::uint32_t*>(creds + 4);
                *reinterpret_cast<std::uint32_t*>(pRequest + 0x18) =
                    *reinterpret_cast<std::uint32_t*>(creds + 8);
                *reinterpret_cast<std::uint16_t*>(pRequest + 0x1c) =
                    *reinterpret_cast<std::uint16_t*>(creds + 12);
                // Remaining credential words via overlapping stores (matches decompile).
                *reinterpret_cast<std::uint32_t*>(pRequest + 0x1e) =
                    *reinterpret_cast<std::uint32_t*>(creds + 14);
                *reinterpret_cast<std::uint32_t*>(pRequest + 0x22) =
                    *reinterpret_cast<std::uint32_t*>(creds + 18);
                *reinterpret_cast<std::uint32_t*>(pRequest + 0x26) =
                    *reinterpret_cast<std::uint32_t*>(creds + 22);
                *reinterpret_cast<std::uint32_t*>(pRequest + 0x2a) =
                    *reinterpret_cast<std::uint32_t*>(creds + 26);

                *reinterpret_cast<std::uint32_t*>(pRequest + kOffParam4) = param4;
                *reinterpret_cast<std::uint16_t*>(pRequest + kOffParam5) =
                    static_cast<std::uint16_t>(param5);

                param5 = pRequest;
                FUN_0046ebf0(); // send / queue prepared request
                return 0;
            }
            pMsg = FUN_0076cec0(&param5, "Password string too long");
            logLine = kLinePassTooLong;
        } else {
            pMsg = FUN_0076cec0(&param5, "Username string too long");
            logLine = kLineUserTooLong;
        }
    }

    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\infrastruct\\Auth\\authClientLib\\AuthClientImpl.cpp",
        logLine,
        3,
        pMsg);
    return 0xffffffff;
}
