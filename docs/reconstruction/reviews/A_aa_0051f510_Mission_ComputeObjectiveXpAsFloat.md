# Review A (reconstruction fidelity): `aa_0051f510` Mission_ComputeObjectiveXpAsFloat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f510` |
| **VA** | `0x0051f510` |
| **Body** | `0x0051f510`–`0x0051f539` (42 bytes) |
| **Canonical name** | `Mission_ComputeObjectiveXpAsFloat` (Ghidra `FUN_0051f510`; **Inferred**) |
| **Review date** | `2026-07-29` (W25-I dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051f510_Mission_ComputeObjectiveXpAsFloat.md` |
| **System** | missions-progression |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs only (no `disassemble_bytes`).

---

## 1. Purpose

Presentation-side **float** wrapper over pure int calculator `Mission_ComputeObjectiveXp`. Sole code caller is `Client_ShowMissionRewardChatToast` (chat / floater display). No character XP mutation, no grant bias.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051f510_FUN_0051f510.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f510_FUN_0051f510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_ComputeObjectiveXpAsFloat.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051f510_FUN_0051f510.md` |
| Live decompile | `decompile_function` @ `0x0051f510` ≡ raw |
| Machine | `read_memory` 48 B @ `0x0051f510`; `g_flZero` @ `0x00a0f518` |
| Callers | `get_function_callers` → `Client_ShowMissionRewardChatToast` |
| Callee dual | `aa_0059dde0` Mission_ComputeObjectiveXp residual seal |

---

## 3. Byte seal (`read_memory` @ `0x0051f510`)

```
8B 4C 24 04        mov  ecx, [esp+4]              ; pObjective
85 C9              test ecx, ecx
74 19              jz   fail
83 B9 4C 01 00 00 00  cmp dword ptr [ecx+0x14c],0
74 10              jz   fail
E8 BA E8 07 00     call Mission_ComputeObjectiveXp ; 0x0059dde0
89 44 24 04        mov  [esp+4], eax
DB 44 24 04        fild dword ptr [esp+4]
C2 04 00           ret  4
fail:
D9 05 18 F5 A0 00  fld  dword ptr [g_flZero]
C2 04 00           ret  4
```

Full body hex (42 B):
```
8b4c240485c9741983b94c010000007410e8bae8070089442404db442404c20400d90518f5a000c20400
```

| Claim | Confidence | Evidence |
|---|---|---|
| Stack formal + `ret 4` | **High** | `[esp+4]`; dual `C2 04 00` |
| ECX setup for fastcall callee | **High** | `mov ecx,[esp+4]` before `call` |
| Callee VA `0x0059dde0` | **High** | rel32 from `0x0051f521` |
| ST0 float return | **High** | `fild` / `fld` then ret |
| `g_flZero` = 0.0f @ `0x00a0f518` | **High** | memory `00 00 00 00` |
| Guard mission def `+0x14c` | **High** | `cmp [ecx+0x14c],0` |
| Leaf of presentation only | **High** | single code xref at toast |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Null / null-def → 0.0f | **Yes** |
| Call Mission_ComputeObjectiveXp | **Yes** |
| int→float via fild | **Yes** |
| ret 4 both paths | **Yes** |
| No bias / no AddExperience | **Yes** |

---

## 5. Caller usage (context only)

`Client_ShowMissionRewardChatToast` @ `0x008ac61b`: after int XP > 0 gate (separate direct calculator call), re-invokes this wrapper for float UI formatting (`FUN_0040dab0` / sprintf "Awarded"). Presentation path only — sealed by parent `aa_0059dde0` dual residual (grant vs presentation split).

---

## 6. Gaps

1. Product/PDB symbol — open (Inferred name).
2. Runtime / bit-exact differential — open.
3. Nested calculator table payloads — owned by `aa_0059dde0`, not required for this wrapper seal.

**Verdict:** **accept**
