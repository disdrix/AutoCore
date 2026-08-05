# Review B (skeptical / adversarial): `aa_0053a260` Map_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-S) |
| **Counterpart** | `reviews/A_aa_0053a260_Map_EraseRange_Val12.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is single-node erase | **Falsified** — range loop + full-clear path; single erase is callee `FUN_005399f0` |
| 2 | Same layout as `Map_EraseNode` `aa_0051cb40` (isnil@+0x29) | **Falsified** — isnil checks at **+0x19** (Val12) |
| 3 | Same as `StdMap_EraseRange` `aa_004bacf0` (isnil@+0x15) | **Falsified** — different isnil offset / callees |
| 4 | cdecl / ret 0 | **Falsified** — **`ret 0x0c`** ⇒ three stack formals + thiscall |
| 5 | Multi-caller shared skill map | **Weakened** — **sole** CODE caller `FUN_0053ba50` |
| 6 | `FUN_00538690` is noreturn always | **Falsified risk** — returns when root isnil@+0x19; full-clear path continues to reset head |
| 7 | Product name known | **Open** — structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range erase + full clear | **High** | leak / double-free |
| ABI ret 0x0c | **High** | stack smash |
| Val12 isnil@+0x19 | **High** | wrong peer family / corruption |
| Successor algorithm | **High** | skip/erase wrong nodes |
| Product map English | Low–Med | naming only |

---

## 3. Cross-check against raw + bytes

```
mov edi, ecx                    // this = map
if (first == *head && last == head) {
  FUN_00538690(head->parent);   // free all non-nil (isnil@+0x19)
  head self-links; size=0; *outIt=*head; ret 0x0c
}
while (first != last) {
  succ = tree_successor(first); // isnil@+0x19
  FUN_005399f0(&first, first);  // Map_EraseNode_Val12
  first = succ;
}
*outIt = first; ret 0x0c
```

Epilogue bytes: `5f 89 30 5e 5b c2 0c 00` + `CC` pad.

Clean must **not** claim isnil@+0x29/+0x15, **not** omit full-clear path, **not** use ret 8 (that is single-node).

---

## 4. Surviving contract for AutoCore

Port as Val12 **range** erase owning policy only; node rebalance/delete owned by `Map_EraseNode_Val12`. Parent `FUN_0053ba50` may delete head after full erase — do not free head inside this unit.

---

## 5. Open questions

1. Exact demangled type for map shell of `FUN_0053ba50`.  
2. Whether any DATA/vtable install sites exist beyond CODE xref (analyze reported 1 CODE).  
3. Runtime / bit-exact open.

**Verdict:** **accept**
