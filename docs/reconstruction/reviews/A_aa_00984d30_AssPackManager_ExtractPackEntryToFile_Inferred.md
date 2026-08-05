# Review A (reconstruction fidelity): `aa_00984d30` AssPackManager_ExtractPackEntryToFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984d30` |
| **VA** | `0x00984d30`–`0x00984ed4` (**421 B**) |
| **Canonical name** | `AssPackManager_ExtractPackEntryToFile_Inferred` |
| **Ghidra name** | `FUN_00984d30` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-Q) |
| **Counterpart** | `reviews/B_aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md` |
| **System** | palantir assets / assPackManager |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + sole call-site bytes. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Extract one named pack entry to a filesystem path under optional host CS; stream-read payload; open-write mode 6; log not-found.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-Q append) | `docs/reconstruction/raw/aa_00984d30_FUN_00984d30.md` |
| Annotated | `docs/reconstruction/raw/aa_00984d30_FUN_00984d30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_ExtractPackEntryToFile_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00984d30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md` |
| Related | W32-E compact sole caller; W31-H open sibling |
| Live | decompile ≡ CF; full hex seals ABI + dual RET 0x0C |

---

## 3. Signature (sealed)

```c
// ECX=outPath, stack host/name/spill, RET 0x0C, returns int 0/-1
int AssPackManager_ExtractPackEntryToFile_Inferred(
    const char* outPath /*ECX*/,
    AssPackHost* host /*stack0*/,
    const char* entryName /*stack1*/,
    uint32_t spill /*stack2*/);
```

| Formal | Source | Conf |
|---|---|---|
| outPath | ECX (`8B D9`) | **High** |
| host | stack0 (`8B 6C 24 …`; `80 7D 50`; `8D 7D 38`) | **High** |
| entryName | stack1 (→ ECX for `FUN_009835f0`; log `%s`) | **High** |
| spill | stack2 (caller empty; fmt-buf reuse) | **Med** |
| return | EAX 0 / −1 | **High** |

---

## 4. Control flow (bytes authority)

```
SEH frame LAB_009b1156
if host.lockEnable(+0x50): EnterCS(host+0x38)
entry = FUN_009835f0()  // EAX=host, ECX=name
if entry == 0:
  log "<%s> couldnt be found!" :0x20f level3
  LeaveCS?; return -1
stream = FUN_00983d40(host)
buf = new[](entry.size+1); stream.vtbl+0x14(buf, size)
path = outPath || entry.defPath(+0x10) || empty
FUN_0076bd90(1); FUN_007669d0(path, 6, 0); WriteFile(...)
close-gate; delete[] buf; stream dtor(1); FUN_00766750
LeaveCS?; return 0
```

| Stage | Match | Conf |
|---|---|---|
| CS gate + leave both paths | decompile ≡ bytes | **High** |
| Lookup miss → −1 | `83 C8 FF` + `C2 0C 00` | **High** |
| Path fallback chain | decompile ≡ bytes (`3B D8` / `PTR_DAT_00afa2bc`) | **High** |
| Write mode 6 | `6A 00 6A 06 53` + `FUN_007669d0` | **High** |
| Success return 0 | `33 C0` + `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (421 B) — see raw W33-Q append.

Entry: `6A FF 68 56 11 9B 00` SEH; `8B 6C 24 2C`; `80 7D 50 00`; `8B D9`.  
Fail epilogue: `83 C8 FF` … `C2 0C 00`.  
Success epilogue: `33 C0` … `C2 0C 00`.  
Pad `CC` then `FUN_00984ee0`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00985010` @ `0x00985169` only |
| Plate | `assPackManager.cpp` |

---

## 7. Gaps

- Nested `FUN_009835f0` / `FUN_00983d40` / stream vtbl product English (not OWN).
- stack[2] product role (always empty from sole caller).
- Exact open-handle identity behind decompiler `HANDLE -1` placeholders.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF + ABI + path fallback + dual epilogues sealed with full hex and sole call-site proof. Nested stream + spill residual → **accept-with-gaps**.
