# Review B (skeptical / adversarial): `aa_006759b0` StdList_BuyNode_Dword

| Field | Value |
|---|---|
| **Stable ID** | `aa_006759b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-M) |
| **Counterpart** | `reviews/A_aa_006759b0_StdList_BuyNode_Dword.md` |
| **Verdict** | **accept** (trivial CF; residual is naming/catalog only) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Auth-only session helper (parent-seed name) | **Falsified** — 40+ CALL sites across sound, UI, map, auth, etc. |
| 2 | Also does list size++ / relink | **Falsified** — body ends after three stores + `ret 0xc`; size/link are callers |
| 3 | Freelist recycle path | **Falsified** — always `operator_new(0xC)` |
| 4 | Value is raw third arg (not deref) | **Falsified** — bytes `8b 11` load from pointer before store |
| 5 | `__cdecl` / bare `ret` | **Falsified** — `c2 0c 00` |
| 6 | Truly `void` (no return) | **Falsified as API** — EAX holds node*; callers assign (decompiler gap only) |
| 7 | Node size other than 0xC | **Falsified** — `push 0xC` |
| 8 | Writes more than 3 dwords / string copy | **Falsified** — 39-byte body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pure buy+init leaf | **High** | inventing size/link breaks every insert site |
| Shared multi-domain identity | **High** | wrong system ownership / Auth-only port |
| stdcall 3-arg ABI | **High** | stack imbalance in ports |
| Return EAX = node* | **High** | dropping return loses head updates |

---

## 3. Cross-check against raw + bytes

```
push 0xC
call operator_new
add  esp, 4
test eax, eax
jz   skip
; store link0, link1, *value
ret  0xC
```

Any clean plate with `list too long`, relink, or freelist is **wrong for this VA**.

Parent-seed `Named_CalleeOf_Auth_AuthServer_*` is **auto-rename debt** — keep as alias only.

---

## 4. Surviving contract for AutoCore

```c
// Port: shared list node buy for T width 4
void *StdList_BuyNode_Dword(void *link0, void *link1, uint32_t *pValue)
{
  uint32_t *n = (uint32_t *)operator_new(0xC);
  if (n) { n[0]=(uint32_t)link0; n[1]=(uint32_t)link1; n[2]=*pValue; }
  return n;
}
// Callers: size++ + splice (e.g. StdList_PushPayloadNode @ 0x00480350)
```

---

## 5. Open questions

1. PDB / compiler symbol string.
2. Whether server ports need an identical helper (usually yes for list-of-pointer queues).

**Verdict:** **accept**
