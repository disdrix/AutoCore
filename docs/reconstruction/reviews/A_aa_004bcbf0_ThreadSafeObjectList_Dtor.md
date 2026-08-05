# Review A (reconstruction fidelity): `aa_004bcbf0` ThreadSafeObjectList_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcbf0` |
| **VA** | `0x004bcbf0`–`0x004bcc31` |
| **Canonical name** | `ThreadSafeObjectList_Dtor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (list dtor drain) |
| **Counterpart** | `reviews/B_aa_004bcbf0_ThreadSafeObjectList_Dtor.md` |
| **System** | client::util / lock-protected object list |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` `0x004bcbf0` + `read_memory` body (66 B) + `analyze_function_complete` + xrefs. No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

Destructor for the dual-CS object list: reinstall vtbl, drain payloads via sealed `PopFront`, delete each payload, zero count, destroy both critical sections.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.md` (+ W25-C) |
| Annotated | `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_Dtor.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bcbf0_ThreadSafeObjectList_Dtor.md` |
| Twin seal | `aa_0040b020` ThreadSafeObjectList_PopFront |
| Live Ghidra | decompile + read_memory + callers |

---

## 3. Signature

```c
void __fastcall ThreadSafeObjectList_Dtor(ThreadSafeObjectList *list);
// ECX = list*; ret
```

| Item | Evidence |
|---|---|
| Body size | 66 B; `004bcbf0`–`004bcc31` |
| Vtbl install | `C7 06 68 B3 9C 00` → `PTR_FUN_009cb368` |
| PopFront calls | two `E8 …` → `0x0040b020` |
| CS deletes | `lea eax,[esi+0x10]` then `add esi,0x28` + `DeleteCriticalSection` |

---

## 4. Control flow (sealed)

```
vtbl = PTR_FUN_009cb368
payload = PopFront(this)
while payload:
  payload->dtor(1)
  payload = PopFront(this)
count = 0
DeleteCS(+0x10); DeleteCS(+0x28)
ret
```

---

## 5. Machine bytes (`read_memory` @ `0x004bcbf0`)

Hex (66 B):  
`568bf157c70668b39c00e821e4f4ff85c074138b106a018bc8ff128bcee80ee4f4ff85c075ed8b3df0619c008d461050c7460c00000000ffd783c62856ffd75f5ec3`

---

## 6. Confidence

| Claim | Level |
|---|---|
| Drain + DeleteCS CF + bytes | **High** |
| Layout twin PopFront | **High** |
| Payload vs node delete distinction | **High** |
| Product English | **Probable** |
| Runtime / bit-exact | **Open** |

---

## 7. Gaps (do not block seal)

1. Product class English name.
2. Per-instance payload type (caller-domain).
3. Runtime hit verification.

**Verdict: accept.**
