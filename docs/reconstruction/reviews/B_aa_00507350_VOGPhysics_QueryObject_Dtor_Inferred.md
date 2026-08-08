# Review B (skeptical / adversarial): `aa_00507350` VOGPhysics_QueryObject_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-028) |
| **Counterpart** | `reviews/A_aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `__fastcall` is true ABI (not thiscall) | **Falsified** — `MOV ESI,ECX` prolog; no stack this; call sites thiscall |
| 2 | `FUN_005ffdb0(0)` is free-standing cdecl with no this | **Falsified** — `MOV ECX,ESI; PUSH 0; CALL` seals thiscall |
| 3 | This VA is the scalar deleting dtor | **Falsified** — scalar is peer `FUN_005073f0` (calls this, then free self tag `0x10`) |
| 4 | Full query base dtor / merges with `005eb210` body | **Falsified** — only header release + buffer free; no triad/float teardown here |
| 5 | Same as TtPhantom dtor / ctor `00581220` | **Falsified** — different VA, vtbl family, size |
| 6 | Releases self refcount @ +6 | **Falsified** — only linked peer @ +0x0C is decremented; self refcount untouched |
| 7 | Always frees buffer @ +0x30 | **Falsified** — signed capacity `JS` skips when high bit set (`0x80000000` empty) |
| 8 | Free size is raw `cap*8` including high bit | **Falsified as risk** — free path only when signed ≥ 0; bytes still `AND 0x7FFFFFFF` before `*8` |
| 9 | Stack-arg dtor / `RET 4` or `RET 8` | **Falsified** — `RET` (`C3`) only |
| 10 | Product English sealed / Runtime Confirmed | **Falsified** — `_Inferred`; no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body dtor role (not scalar) | **High** | double-free / wrong free size |
| Linked-only refcount release | **High** | leak or use-after-free of peer |
| Capacity sentinel skip | **High** | free of unallocated buffer |
| thiscall RET 0 | **High** | stack smash if port adds cleanup |
| Pair with SubInit layout | **High** | offset drift vs ctor |
| Product English | Medium | naming only |
| Flag-word@+4 dual meaning | Med | wrong scalar free size in wrapper |

---

## 3. Cross-check against raw + bytes

```
*this = vtbl_009cd99c
if linked@+0x0C:
  if --linked->rc(+6) == 0: linked->vtbl[0](1)
if (int)cap@+0x38 >= 0:
  pool_free(buf@+0x30, (cap&0x7FFFFFFF)*8, tag=0x12)
*this = vtbl_009d81e8
if (int16)flags@+4 < 0:
  flags &= 0x7FFF; FUN_005ffdb0(this, 0)
*this = vtbl_009cc290
ret
```

Clean must **not** invent self-refcount release, always-free buffer, scalar-delete of `this`, stack args, TtPhantom identity, product English, or Runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// Body dtor for query-object header (thiscall, RET 0)
void VOGPhysics_QueryObject_Dtor(QueryObjectHeader self)
{
    self.Vtbl = Provisional_009cd99c;
    var linked = self.Linked; // +0x0C
    if (linked != null && --linked.RefCount == 0)
        linked.ScalarDeleteOrRelease(1);
    if ((int)self.Capacity >= 0) // +0x38; empty = 0x80000000
        PoolFree(self.Buffer, (self.Capacity & 0x7FFFFFFF) * 8, tag: 0x12);
    self.Vtbl = Mid_009d81e8;
    if ((short)self.FlagWord < 0) { // +0x04
        self.FlagWord &= 0x7FFF;
        FlagClearHelper(self, 0); // FUN_005ffdb0
    }
    self.Vtbl = Base_009cc290;
}
```

Port must keep **linked-only** release, **signed capacity** free gate, **three vtbl stages**, and pair with SubInit `00581190` offsets. Scalar deleting wrapper `005073f0` is separate.

---

## 5. Open questions

1. Product/PDB class name for the three vtbl stages.  
2. Whether flag word @ +4 is exclusively ownership, or also the allocation size used by scalar free.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
