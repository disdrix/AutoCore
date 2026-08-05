# OWN-ONLY dual agent report — W25-R

| Field | Value |
|---|---|
| Agent | W25-R |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0043c5f0`, `0x00767600` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x0043c5f0` — GuardedVector_AssignTo

| Field | Value |
|---|---|
| Ghidra | `FUN_0043c5f0` |
| Canonical | `GuardedVector_AssignTo` (**Inferred**) |
| Body | `0x0043c5f0`–`0x0043c650` (last `ret 4`) |
| Role | Optional CS around container assign (`FUN_0043c730`) |
| ABI | ECX=`source`, stack `dest*`, **`ret 4`** |
| Offsets | CS `+0x14`; lock-enable `char +0x2c` |
| Callers | `NDResourceCache_LookupOrCreate` + 6 registry readers |
| Callees | `EnterCriticalSection`, `LeaveCriticalSection`, `FUN_0043c730` |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0043c5f0_FUN_0043c5f0.md`
- `docs/reconstruction/raw/aa_0043c5f0_FUN_0043c5f0.annotated.md`
- `docs/reconstruction/reconstructed-exact/GuardedVector_AssignTo.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0043c5f0.cpp`
- `docs/reconstruction/functions/aa_0043c5f0_GuardedVector_AssignTo.md`
- `docs/reconstruction/functions/aa_0043c5f0_FUN_0043c5f0.md`
- `docs/reconstruction/reviews/A_aa_0043c5f0_GuardedVector_AssignTo.md`
- `docs/reconstruction/reviews/B_aa_0043c5f0_GuardedVector_AssignTo.md`

---

## VA `0x00767600` — stoChunk_ConvertToInteger

| Field | Value |
|---|---|
| Ghidra | `FUN_00767600` |
| Canonical | `stoChunk_ConvertToInteger` (**High** — plate string) |
| Body | `0x00767600`–`0x007677f6` |
| Role | Decimal text → integer bytes (1/2/4/8), signed/unsigned |
| ABI | EAX=`const std::string*`, stack `(out, byteLen, signedMode)`, **`ret 12`** |
| Returns | `0` success, `−1` fail |
| Callers | Text readers `00768260`…`00769660` incl. `stoChunkReader_TextReadU32` |
| Callees | `__allmul`, `isdigit`, `vog_LogMessage` |
| Live ≡ raw | Yes |
| **Verdict** | **accept** |

### Artifacts

- `docs/reconstruction/raw/aa_00767600_FUN_00767600.md`
- `docs/reconstruction/raw/aa_00767600_FUN_00767600.annotated.md`
- `docs/reconstruction/reconstructed-exact/stoChunk_ConvertToInteger.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00767600.cpp`
- `docs/reconstruction/functions/aa_00767600_stoChunk_ConvertToInteger.md`
- `docs/reconstruction/functions/aa_00767600_FUN_00767600.md`
- `docs/reconstruction/reviews/A_aa_00767600_stoChunk_ConvertToInteger.md`
- `docs/reconstruction/reviews/B_aa_00767600_stoChunk_ConvertToInteger.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write artifacts for non-owned helpers (`0043c730`, `__allmul`, text readers, etc.).
- Named clean plates preferred; FUN_* aliases point at sealed CF.
- Prior raw bodies preserved; W25-R live seal sections appended only.
