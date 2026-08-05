# Review A (reconstruction fidelity): `aa_00521900` Character_GetClassDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521900` |
| **VA** | `0x00521900` |
| **Body** | `0x00521900`–`0x0052193b` (**59 B** / `0x3b`); pad `CC` |
| **Canonical name** | `Character_GetClassDisplayName_Inferred` (**Inferred**); Ghidra `FUN_00521900` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00521900_Character_GetClassDisplayName_Inferred.md` |
| **System** | missions-progression / character display |
| **Live tools** | Ghidra `batch_decompile`, `get_function_by_address`, `get_function_callers`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — load + 2-arg lookup + ring sealed; class English table owned by unowned `FUN_0051f940` |
| **Dual status** | **Present (WQ7R-F)** |

---

## 1. Purpose

Character **class display name** helper: read class/race bytes from the same nested blob as the race helper, look up product English via `FUN_0051f940`, ring-buffer, return.

```
blob = nested(this)
classId = *(uint8*)(blob + 0x531)
raceId  = *(uint8*)(blob + 0x532)
name = FUN_0051f940(classId, raceId)   // cdecl, 2 args
return FUN_007a6de0(FUN_007a69d0(), name, -1)
```

**ABI:** ECX-this; plain **`RET`**; returns **char\*** (TLS ring).

Mission token: parent `FUN_005465c0` replaces **`[$class]`** (len 8).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` `0x00521900` + callee `0x0051f940` |
| Body bounds | `get_function_by_address` → `00521900`–`0052193b` |
| Machine | `read_memory` 80 B @ entry |
| Callers | `FUN_005465c0`, `FUN_005792d0`, `FUN_0092e5d0`, `FUN_0092e710` |
| Scaffold | prior raw/annotated/clean updated WQ7R-F |

**Not performed:** Launcher, runtime golden, bit-exact, parent ledgers, dual of `FUN_0051f940`.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| ECX-this | `8b 41 04` | **Confirmed** |
| Nested path shared with race helper | same `+4/+4/+0xac+this/+0x3c` bytes | **Confirmed** |
| Race byte load | `8a 88 32 05 00 00` → cl | **Confirmed** |
| Class byte load | `8a 80 31 05 00 00` → al | **Confirmed** |
| Push order class, race; cdecl clean 8 | `51 52 e8 … 83 c4 08` (after movzx) | **Confirmed** |
| `-1` is buffer length, not 3rd lookup arg | `6a ff` before lookup; remains after `add esp,8` for `007a6de0` | **Confirmed** |
| Ring path | push name; call `007a69d0`; mov ecx,eax; call `007a6de0`; ret | **Confirmed** |
| char\* return | parent replace / strcpy consumers | **Confirmed** |

### Class table (supporting decompile of unowned `FUN_0051f940`)

| classId | race0 | race1 | race2 | else |
|---|---|---|---|---|
| 0 | Commando | Champion | Terminator | Commando |
| 1 | Engineer | Shaman | Constructor | Engineer |
| 2 | Lieutenant | Archon | MasterMind | Officer |
| 3 | Bounty Hunter | Avenger | Agent | Ranger |
| other | Unknown | | | |

Table is **High** from callee decompile, not dual-owned in WQ7R-F.

---

## 4. Gaps

- Product method English.
- Dual seal of `FUN_0051f940` (class×race leaf).
- Deep Character / blob C++ types.
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — this unit's CF and ABI sealed; class English depends on unowned leaf (documented, not dualed here).
