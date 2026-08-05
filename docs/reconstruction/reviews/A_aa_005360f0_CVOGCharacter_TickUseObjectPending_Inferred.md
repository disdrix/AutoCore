# Review A (reconstruction fidelity): `aa_005360f0` CVOGCharacter_TickUseObjectPending_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005360f0` |
| **VA** | `0x005360f0`–`0x00536143` (84 B) |
| **Canonical name (proposed)** | `CVOGCharacter_TickUseObjectPending_Inferred` |
| **Ghidra name** | `FUN_005360f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_005360f0_CVOGCharacter_TickUseObjectPending_Inferred.md` |
| **System tag** | `missions-progression` |
| **Agent** | W26-S OWN-ONLY |
| **Verdict** | **accept** on CF / ABI / timer / commit-on-expiry; **accept-with-gaps** only on product English |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs/callers. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

Character-side **pending use-object countdown tick**: advance `+0xc80` by frame dt when gates pass; on expiry call `ResolveUseObjectPending(commit=1)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_005360f0` @ `0x005360f0` (≡ raw CF) |
| Body | `0x005360f0`–`0x00536143` |
| Prologue / gates | vbase `+0xa8` / `+0x7e`; `+0xc7c`; COMISS timer |
| Epilogue | `B0 01 C2 04 00` / `32 C0 C2 04 00` |
| Caller | `FUN_00930040` @ `0x009300c3` push `[DAT_00d09874+0x30]` |
| Callee dual | W25-A `CVOGCharacter_ResolveUseObjectPending_Inferred` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body end `0x00536143` | **High** | `get_function_by_address` |
| `__thiscall` + `ret 4` | **High** | `C2 04 00` |
| ECX=character | **High** | offsets `+0xc7c/+0xc80` match Resolve dual |
| Timer subtract dt | **High** | `subss xmm0,[esp+4]` |
| Commit = 1 on ≤0 | **High** | `6A 01` + call |
| Live ≡ raw CF | **High** | re-decompile 2026-07-29 |
| Product English | **Probable** | `_Inferred` |

---

## 4. Sealed control flow

```
TickUseObjectPending(char, dt) -> bool
  if !vbase(+0x7e) or !flag(+0xc7c) or !(timer(+0xc80) > 0):
    return false
  timer = timer - dt
  if timer <= 0:
    ResolveUseObjectPending(char, commit=1)
  return true
```

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Triple gate | **Yes** |
| Subtract / store | **Yes** |
| Commit on expiry | **Yes** |
| Bool return polarity | **Yes** |
| Invented callers | **None** — sole CODE xref listed |

---

## 6. Gaps / open questions

1. Product/PDB method name.
2. Arming path for initial `+0xc80` value (not this unit).
3. Runtime / bit-diff.
