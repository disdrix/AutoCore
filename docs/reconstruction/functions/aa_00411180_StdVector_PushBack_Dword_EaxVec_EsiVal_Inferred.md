# Function record: StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411180` |
| **Canonical name** | `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` |
| **Ghidra name** | `FUN_00411180` |
| **Address** | `0x00411180`–`0x004111c9` (74 B measured) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container util |
| **Classification** | worker |
| **Dual** | WQ7R-D 2026-08-04 — **accept-with-gaps** |
| **Name confidence** | Inferred (structural; multi-caller generic) |

## Role

Dword-vector push_back with customcall **EAX=vec / ESI=value***. Sibling of sealed `Vector_PushDword` (`0x004149d0`) but different ABI and grow chain (`FUN_0040b6d0` vs `FUN_0040dbf0`).

## Journal coupling (site-level only)

`Client_UpdateMissionJournal` pushes into host vectors at `+0x728` / `+0x738` with stack dword values — body has **no** mission-specific logic.

## See also

- Ghidra twin record: `aa_00411180_FUN_00411180.md`
- Grow residual: `aa_0040b6d0` (WQ7R-E)
- Historical thiscall sibling: `aa_004149d0` / `Vector_PushDword`
