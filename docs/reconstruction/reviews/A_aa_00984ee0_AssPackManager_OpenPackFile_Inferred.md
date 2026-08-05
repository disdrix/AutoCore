# Review A (reconstruction fidelity): `aa_00984ee0` AssPackManager_OpenPackFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984ee0` |
| **VA** | `0x00984ee0`–`0x00985006` (**295 B**) |
| **Canonical name** | `AssPackManager_OpenPackFile_Inferred` |
| **Ghidra name** | `FUN_00984ee0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-H) |
| **Counterpart** | `reviews/B_aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md` |
| **System** | palantir assets / assPackManager |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + call-site bytes. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Open a pack file path under optional manager CS: construct 0x44 pack, open, push pointer into manager vector @+0x28; log Opening/FAILED/SUCCESS.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-H append) | `docs/reconstruction/raw/aa_00984ee0_FUN_00984ee0.md` |
| Annotated | `docs/reconstruction/raw/aa_00984ee0_FUN_00984ee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_OpenPackFile_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00984ee0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md` |
| Related | W30-D `AssManager_InitPrecompileAndResolvers` batch caller |
| Live | decompile ≡ CF; full hex seals ABI + vector push |

---

## 3. Signature (sealed)

```c
// EBX=self, ECX=path, stack char flag, RET 4, returns int 0/-1
int AssPackManager_OpenPackFile_Inferred(const char* path /*ECX*/, char flag /*stack*/,
                                         AssPackManager* self /*EBX*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | EBX (`80 7B 50`, `8D 6B 38`, callers `8D 58 08`) | **High** |
| path | ECX (`8B F1`) | **High** |
| flag | stack (`RET 4`; ctor arg) | **High** |
| return | EAX 0 / −1 | **High** |

---

## 4. Control flow (bytes authority)

```
SEH frame LAB_009b1173
if self.lockEnable(+0x50): EnterCS(self+0x38)
log Opening path
pack = new(0x44); if pack: FUN_00719970(pack, flag)
rc = FUN_0071a9d0()  // EAX=path, EDI=pack
if rc < 0:
  log FAILED; LeaveCS?; return -1
log SUCCESS
FUN_004406e0()  // EAX=self+0x28, ESI=&pack*
LeaveCS?
return 0
```

| Stage | Match | Conf |
|---|---|---|
| CS gate + leave both paths | decompile ≡ bytes | **High** |
| new 0x44 + ctor | decompile ≡ bytes | **High** |
| open fail → −1 | `83 C8 FF` + `C2 04 00` | **High** |
| vector push @ +0x28 | `8D 43 28` + `FUN_004406e0` | **High** |
| success return 0 | `33 C0` + `C2 04 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (295 B) — see raw W31-H append.

Entry: `6A FF 68 73 11 9B 00` SEH; `80 7B 50 00`; `8D 6B 38`; `8B F1`.  
Fail epilogue: `83 C8 FF` … `C2 04 00`.  
Success epilogue: `33 C0` … `C2 04 00`.  
Pad `CC` then `FUN_00985010`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_007b75b0` (batch), `FUN_00985010`, `FUN_009963f0` |
| Plate | `assPackManager.cpp` |

---

## 7. Gaps

- Nested `FUN_0071a9d0` / pack class product English (not OWN).
- Fail path: pack object not freed in this body (leak vs caller residual open).
- Runtime / bit-exact / contended CS.

---

## 8. Verdict

CF + ABI + layout sealed with full hex and call-site proof. Nested free + product demangle residual → **accept-with-gaps**.
