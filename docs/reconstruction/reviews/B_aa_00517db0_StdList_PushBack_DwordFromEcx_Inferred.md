# Review B (skeptical / adversarial): `aa_00517db0` StdList_PushBack_DwordFromEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517db0` |
| **VA** | `0x00517db0`–`0x00517de9` |
| **Canonical name** | `StdList_PushBack_DwordFromEcx_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Reviewer role** | OWN-ONLY dual **R10-032** Path B |
| **Counterpart** | `reviews/A_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` |
| **System** | shared MSVC `std::list` |
| **Live tools** | same live set as A (decompile / `read_memory` / xrefs / callers); **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Mission-progression exclusive helper | 5 code parents + 18 DATA vtable xrefs across classes | **Falsified** — shared list utility; partition is seed only |
| 2 | Same ABI as `StdList_PushBack_Dword` `0x00402d10` (ECX=list) | Bytes: `MOV EBX,[ESP+…]` loads list from stack; ECX spilled as **value** | **Falsified** merge — inverted list/value placement |
| 3 | `std::vector` grow / contiguous push | Allocates **0xC node** + circular Next/Prev; Incsize list max | **Falsified** as vector |
| 4 | Push-**front** (insert after head Next) | Writes **`[head+4]`** (Prev) and `old_prev->Next`; BuyNode `Next=head` | **Falsified** front — sealed **push_back** |
| 5 | Uninitialized local value (decompiler `local_4`) | Entry `PUSH ECX`; `MOV [slot],ECX`; LEA passes `&slot` | **Falsified** uninit — value **is** entry ECX |
| 6 | cdecl / bare RET / no stack cleanup | Epilogue `C2 04 00` | **Falsified** — **RET 4** |
| 7 | Leaf | Calls `00418700` + `00404840` | **Falsified** leaf |
| 8 | Incsize never throws | Dualed callee builds `"list<T> too long"` + throw | **Falsified** no-throw |
| 9 | Node embeds full object blob | BuyNode copies **one dword** (ECX) to `node+8` | **Falsified** bulk embed |
| 10 | Merge with PushFront_DwordFromEax `004027f0` | Peer is **front** splice + **EAX=const T*** + different Incsize VA | **Falsified** merge |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List head `+4` / size `+8` | **High / Sealed** | Wrong container port |
| 0xC node dword payload = ECX | **High / Sealed** | Wrong value source / width |
| Push-back splice | **High / Sealed** | Iterator order bugs |
| Stack list + ECX value + RET 4 | **High / Sealed** | Stack corruption / wrong this |
| Shared multi-caller / vtable | **High / Sealed** | Wrong domain ownership |
| Product `T` name | **Tentative** | Misnamed mission-only API |
| Null-new path | **Open** | Crash if `new` fails |
| Runtime | **Open** | — |

---

## 3. Cross-check

```
raw 2026-07-23 ≡ live decompile 2026-08-05 CF
read_memory hex seal (58 B) ≡ RET 4 ≡ body bounds
FUN_00418700: new(0xC); node={head, head->Prev, *pValue}; RET 0xC  (parent dual)
FUN_00404840: if 0x3fffffff - size < n → throw; else size += n; RET 4  (R10-006)
Parents: 004c30d0 / 004f46c0 / 00562fa0 / 00587680 (CALL) + 00569ba0 (JMP after this-adjust)
DATA: 18 vtable-style slots → multi-class virtual "push this on list"
```

### Mission-name trap

Do **not** invent product mission plates. Partition seed only. Canonical is structural `_Inferred` list helper.

### 00402d10 ABI trap

Do **not** port as thiscall-list. Here **list is stack**, **value is ECX**. Swapping them corrupts every virtual caller.

### Uninit-local trap

Decompiler `undefined1 local_4[4]` looks like garbage push_back. Bytes prove **ECX spill**. Port must store the register value (typically `this`).

### Front/back trap

Same Prev-at-head pattern as dualed PushBack_Dword → **push_back**. Do not rename PushFront without new evidence.

### Null-new trap

`FUN_00418700` returns 0 on failed `operator_new`; this unit still stores through `node`. Port may crash on OOM — matches retail risk.

---

## 4. Surviving contract for AutoCore

```
void StdList_PushBack_DwordFromEcx_Inferred(list* /*stack*/, uint32_t value /*ECX*/);
// RET 4
// buy 0xC node; Incsize(1); splice before sentinel
// value source = ECX (not *ptr, not list*)
```

Port notes:
- Use for observer/listener registration patterns: `list.push_back(this)`.
- Do not merge with `0x00402d10` or `0x004027f0` ABIs.
- Preserve throw path via Incsize.

---

## 5. Verdict rationale

Adversarial attacks on mission-only, vector, front, uninit-local, and ECX=list merge all fail against live bytes + dualed callees. Product `T` and runtime remain open → **accept-with-gaps** (not reject: contract is port-usable).
