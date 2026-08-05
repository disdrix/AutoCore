# Review A (reconstruction fidelity): `aa_0053ada0` CNDHash_FreelistPop_Node0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053ada0` |
| **VA** | `0x0053ada0` |
| **Canonical name** | `CNDHash_FreelistPop_Node0x1c` (slab freelist pop for 0x1c nodes) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053ada0_CNDHash_FreelistPop_Node0x1c.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile, insert callers, `FUN_004073a0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Freelist pop** for CNDHash **0x1c-byte** nodes — `__fastcall` / ECX = freelist control (typically `hash+0x20` embed):

1. If freelist head empty (`*head==0` or `**head==0` path):
   - `_aligned_malloc(700, 0x10)` — slab.
   - Track slab pointer in growable ptr vector (`param_1[2..4]` begin/end/cap style); may call `FUN_004073a0` InsertN dword.
   - Chain **0x18 (24)** nodes: each `*node = node+7 dwords` (`+0x1c` stride).
   - Terminate last: `slab[0xa8] = 0` (offset `0xa8*4 = 0x2A0`; 24×0x1c = 0x2A0 — last next null).
2. Pop: `*head = **head` (advance freelist); return via mutated head / EAX convention used by inserts.

Used by all mission-family inserts: `0x0053c360`…`0x0053c760`, `CNDHash_Insert` `0x0053c560`, plus other insert sites.

Math check: 24 × 0x1c = 672; aligned malloc 700 with 16-align → enough for chain + pad.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live A/B | batch + force — **identical** |
| Insert consumers | `0053c360/460/560/660/760` |
| Vector grow | `FUN_004073a0` (already dualed) |

---

## 3. Confidence

| Claim | Level |
|---|---|
| CF A≡B | **Confirmed** |
| Node stride 7 dwords (0x1c) | **Confirmed** |
| Slab count 0x18 | **Confirmed** |
| Aligned 700 / 0x10 | **Confirmed** |
| ECX = freelist object (hash+0x20) | **High** (call sites) |
| Exact freelist header layout product name | **Probable** |

---

## 4. Recovered CF

```c
// void __fastcall FreelistPop(Freelist *fl)  // mutates fl->head; node at old head
if (!fl->head || !*fl->head) {
  slab = _aligned_malloc(700, 16);
  // push slab* into fl's slab vector (InsertN or in-place)
  fl->head = slab;
  for (i=0;i<0x18;i++) link node[i] -> node[i+1] by +0x1c;
  last->next = 0;
}
fl->head = *fl->head; // pop
```
