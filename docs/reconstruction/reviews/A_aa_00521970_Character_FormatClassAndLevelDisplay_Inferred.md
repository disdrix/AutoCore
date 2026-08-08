# Review A (reconstruction fidelity): `aa_00521970` Character_FormatClassAndLevelDisplay_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521970` |
| **VA** | `0x00521970`–`0x00521a62` exclusive (**242 B** / `0xF2`); pad `CC` |
| **Canonical name** | `Character_FormatClassAndLevelDisplay_Inferred` (**Inferred**); Ghidra `FUN_00521970` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00521970_Character_FormatClassAndLevelDisplay_Inferred.md` |
| **System** | skills-abilities / character display |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `get_function_by_address`, callers/xrefs/`get_bulk_xrefs`, `read_memory`, `search_byte_patterns`, callee decompiles (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/RET4/class×level sprintf + product strings sealed; callers + product method English open |
| **Dual status** | **Present (R10-034)** |

---

## 1. Purpose

Character **class and optional level** display formatter: load class/race from the shared nested blob, look up product English via dualed `LookupClassDisplayName_Inferred` (`FUN_0051f940`), optionally localize `"Level"` + re-fetch vcall level, and `sprintf` into a caller-owned buffer.

```
tls = FUN_007a69d0()
level = this->vcall(+0x27c)()
blob = nested(this)
className = ring( FUN_0051f940(blob+0x531, blob+0x532) )
if (level >= 0):
  sprintf(out, "%s, %s %i", className, ring_tls("Level"), level)
else:
  sprintf(out, "%s", className)
```

**ABI:** ECX-this; stack `char* out`; plain **`RET 4`**; void (writes buffer).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` `0x00521970` 2026-08-05 |
| Body bounds | `get_function_by_address` → `00521970`–`00521a62` |
| Machine | `read_memory` 256 B @ entry + string VAs |
| Parent leaf dual | `A/B_aa_0051f940_LookupClassDisplayName_Inferred` |
| Sibling dual | `Character_GetClassDisplayName_Inferred` (`aa_00521900`) |
| Scaffold | raw/annotated/clean updated R10-034 (raw append-only) |

**Not performed:** Launcher, runtime golden, bit-exact, parent ledgers, dual of other VAs.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| ECX-this | `8B F1` after push ebx/esi | **Confirmed** |
| `RET 4` both exits | `C2 04 00` at end of each path | **Confirmed** |
| Nested blob path shared with class/race helpers | `+4/+4/+0xac+this/+0x3c` | **Confirmed** |
| Class `@+0x531` / race `@+0x532` | `8A 80 31 05 00 00` / `8A 88 32 05 00 00` | **Confirmed** |
| cdecl 2-arg `FUN_0051f940` | push race, push class, `call`, `83 C4 08` | **Confirmed** |
| `-1` is buffer length | `6A FF` survives past `add esp,8` into `007a6de0` | **Confirmed** |
| Level vcall `+0x27c` | `FF 92 7C 02 00 00` twice on ≥0 path | **Confirmed** |
| Branch on level < 0 | `85 C0 7C 7C` | **Confirmed** |
| Product `"Level"` | imm `0x00a41404` → `Level\0` | **Confirmed** |
| Formats | `"%s, %s %i"` @ `0x009cf10c`; `"%s"` @ `0x00a2c2a4` | **Confirmed** |
| IAT sprintf | `FF 15 54 66 9C 00` | **Confirmed** |

### Class table (supporting — owned by dualed leaf `0x0051f940`)

| classId | race0 | race1 | race2 | else |
|---|---|---|---|---|
| 0 | Commando | Champion | Terminator | Commando |
| 1 | Engineer | Shaman | Constructor | Engineer |
| 2 | Lieutenant | Archon | MasterMind | Officer |
| 3 | Bounty Hunter | Avenger | Agent | Ranger |
| other | Unknown | | | |

Table dual-sealed under parent dual of `LookupClassDisplayName_Inferred` (not re-owned here).

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| TLS fetch + level vcall probe | **Yes** |
| level < 0 → class-only sprintf | **Yes** |
| level ≥ 0 → class + Level + int sprintf | **Yes** |
| 2-arg class lookup + ring | **Yes** (bytes-corrected vs decompiler 3-arg) |
| `RET 4` both paths | **Yes** |

---

## 5. Gaps

1. Product/PDB method English (name is role-**Inferred**).
2. Zero sealed direct callers / out-buffer producers (live xrefs empty).
3. Deep Character / blob C++ types.
4. Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — this unit's CF, ABI, product format strings, and class×level formatting role sealed; callers + product method English residual.
