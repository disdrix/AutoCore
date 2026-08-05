# Review B (skeptical / adversarial): `aa_00419bd0` CNDHash_FreelistPop_Node0x28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419bd0` |
| **VA** | `0x00419bd0` |
| **Canonical name** | `CNDHash_FreelistPop_Node0x28` (inferred) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00419bd0_CNDHash_FreelistPop_Node0x28.md` |
| **System** | container / CNDHash |
| **Live tools** | Ghidra `decompile_function`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** on CF/ABI/math; product English name remains **Probable** only |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void` means no return | Insert `puVar2 = FUN_00419bd0()`; body `mov eax,[edi]` before advance | **Falsified** — returns `Node*` in EAX |
| 2 | Mission-fail / FailMissionNotify product role | Callee `0x004149d0` dual = Vector_PushDword; only tracks slab pointer | **Falsified** mission role |
| 3 | Coverage name `Mission_Uses_CVOGReaction_FailMissionNotify_*` | Keyword from callee string graph only | **Falsified** as product name |
| 4 | Same as `CNDHash_FreelistPop_Node0x1c` (`0053ada0`) | That unit: 700 slab, stride 0x1c; this: 1000, 0x28 | **Falsified** equality — same **pattern**, different geometry |
| 5 | `__thiscall` ECX = freelist | Body uses **EDI**; ECX only set to EDI+4 for track call | **Falsified** pure-thiscall model |
| 6 | Stride 10 bytes or 0x10 | `lea ecx,[eax+0x28]`; decomp `+10` on `int*` | **Falsified** — **0x28** |
| 7 | Unlimited malloc every pop | Grow only when empty; then always pop | **Falsified** always-malloc |
| 8 | 25 usable nodes (1000/0x28) | Terminator at 0x3c0 with next=0; usable walk is 24 pops | **Attack fails on 24 usable** — 25th slot is null terminator |
| 9 | `ret 4` / stdcall | Epilogue `59 c3` (pop ecx local; ret) | **Falsified** — no stack arg cleanup |
| 10 | Runtime / bit-exact verified | Static only | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slab 1000 / align 0x10 | **Confirmed** | Wrong pool size |
| Stride 0x28 | **Confirmed** | Node overlap / corruption |
| 24 links + term @ 0x3c0 | **Confirmed** | Off-by-one free count |
| EDI head / EAX return | **Confirmed** | Insert uses garbage node |
| Vector_PushDword residue | **High** | Wrong mission coupling in port |
| Freelist embeds at hash+0x20 | **High** | insert dual; not re-proven for every future caller |
| Product English name | **Medium** | Docs only |
| OOM if malloc NULL | **Open** | Crash path unhandled in retail too |

---

## 3. Cross-check against raw / bytes

```text
// raw decompile (register fiction):
if ((*unaff_EDI == 0) || (**(int**)unaff_EDI == 0)) {
  slab = _aligned_malloc(1000, 0x10);
  CVOGReaction_FailMissionNotify(&local_4); // ECX=EDI+4 machine
  *unaff_EDI = slab;
  for (i=0x18; i; --i) { *p = p+10; p += 10; } // +0x28
  slab[0xf0] = 0; // +0x3c0
}
*unaff_EDI = **(int***)unaff_EDI; // + EAX=old head on machine
```

Hex (full body 94 bytes):  
`518b0785c07405833800754b566a1068e8030000ff15ac659c008bf083c4088d442404508d4f0489742408e8d0adffff89378bc6ba180000008da4240000000083ea018d482889088bc175f4c786c0030000000000005e8b078b08890f59c3`

Sibling insert (`aa_00413920`) seals: after this call, node fields at +0xc / +0x18 / +0x1c written — freelist only delivered raw 0x28 storage.

### Rename trap

`Mission_Uses_CVOGReaction_FailMissionNotify_00419bd0` is **keyword contamination**. Function is a **CNDHash freelist pop**, not mission fail.

---

## 4. Surviving contract for AutoCore

```
CNDHash_FreelistPop_Node0x28 (custom ABI):
  in  EDI = Node **pHead   // typically hash+0x20
  out EAX = Node*          // popped slot
  if empty:
    slab = _aligned_malloc(1000, 16)
    Vector_PushDword(pHead+1 /*+4*/, &slab)  // residue name FailMissionNotify
    chain 24 nodes of 0x28; [slab+0x3c0]=0
  pop head

AutoCore must NOT:
  - treat decompiler void as no return value
  - call mission-fail APIs here
  - use 0x1c mission-node stride for this pool
  - grow on every successful pop
  - assume thiscall ECX=hash for this leaf
```

**Port tests:**

* Empty head → one malloc, 24 usable pops, 25th call grows again.
* Non-empty → no malloc; head advances.
* Insert after pop initializes full 0x28 node (vtbl/key/value) — not this unit’s job.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Freelist pop 0x28 / slab 1000 | **Agree Confirmed** |
| FailMissionNotify = Vector_PushDword residue | **Agree High** |
| EAX return Confirmed | **Agree** |
| 24 usable + term @ 0x3c0 | **Agree** (reject “25 free nodes”) |
| accept | **Agree** (name Probable) |

---

## 6. Open questions

1. Slab free / process teardown path (out of OWN scope).
2. Whether `FUN_00419620` is byte-identical insert twin or shares only freelist setup.
3. Live multi-slab growth under inventory sheet flood.

**Verdict:** **accept** — adversarial checks strengthen machine ABI/CF/math; do not couple to mission-fail or 0x1c freelist geometry.
