# Review B (skeptical / adversarial): `aa_0059c8a0` FreelistSlabVector_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059c8a0` |
| **VA** | `0x0059c8a0` |
| **Canonical name** | `FreelistSlabVector_dtor` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0059c8a0_FreelistSlabVector_dtor.md` |
| **Live tools** | Independent decompile + `read_memory` + multi-caller ECX adjust sample |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Trust Ghidra noreturn on `operator_delete` | Bytes continue to three null stores | **Falsified** noreturn |
| 2 | Zero only on null-begin path | `jz` skips only the delete call | **Falsified** — zero always |
| 3 | Also frees freelist nodes at head | No access to `+0`; nodes already freelist-linked | **Falsified** node-free claim |
| 4 | ECX is always full CNDHash* | Call sites use `lea ecx,[reg+0x20]` (e.g. `0053b976`) | **Falsified** full-hash this |
| 5 | `free` not `_aligned_free` | IAT load `0x009c6578` + indirect call | **Attack fails** — aligned |
| 6 | Product name exact | No PDB | **Open** — inferred OK |

---

## 2. Surviving contract

```
FreelistSlabVector_dtor(this /* freelist subobject */):
  for it in [begin, end): _aligned_free(*it)
  if begin: operator_delete(begin)  // returns
  begin = end = capacity_end = 0
  // head at +0 untouched
```

### Traps

1. **Never** pass raw CNDHash* without `+0x20` — destroys wrong memory.
2. **Do not** skip FreeBuckets first — slabs free after nodes reclaimed to head; head not cleared here.
3. **Do not** model as noreturn after `operator_delete`.
4. Thunk `0059cbc0` is not a second implementation.

**Verdict:** **accept.** Accept A.
