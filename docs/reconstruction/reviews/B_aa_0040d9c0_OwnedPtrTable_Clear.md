# Review B (skeptical / adversarial): `aa_0040d9c0` OwnedPtrTable_Clear

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d9c0` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B, W18-M) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040d9c0_OwnedPtrTable_Clear.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | ECX is this | Call sites move/lea into **ESI** before CALL | **Falsified** — ESI this |
| 2 | `operator_delete` never returns | Bytes: `ADD ESP,4` then loop/compare | **Falsified** — Ghidra false warning |
| 3 | First loop is no-op / can assign 0 | Equivalent end state is zero, but intermediate decrements may matter if re-entered | **Clarify** — end state sealed; intent of spin **Tentative** |
| 4 | std::vector full layout (capacity at +0x0C) | `+0x0C` is nulled like a cache ptr, not used as capacity in free math | **Sealed** as cache field, not capacity |
| 5 | Dual decompiles disagree | force ≡ decompile | **No conflict** |
| 6 | Has only delete callee | analyze complete | **Sealed** |
| 7 | Name is studio-official | No RTTI in body | **Tentative** inferred |
| 8 | Elements are POD needing no dtor | Body never calls vtable dtor — either POD/raw or leak of side effects | **Gap** if typed objects expected |
| 9 | Thunk at `0x0040fd50` is different function | `JMP 0x0040d9c0` | **Falsified** — pure thunk |
| 10 | SEH wrapper is same VA | `FUN_0040d910` is distinct entry that calls this | **Clarify** — not this unit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-all CF | **High** | Leaks / double-free if mis-ported |
| ESI ABI | **High** | Wrong object destroyed |
| Layout offsets | **High** | Corrupt neighbors |
| liveCount meaning | **Low–Medium** | Wrong concurrent model |
| Element ownership model | **Medium** | Missing dtor side effects |
| Inferred name | **Medium** | Rename churn |

---

## 3. Cross-check: decompile vs bytes

| Step | Decompile | Bytes |
|---|---|---|
| this | `unaff_ESI` | ESI loads/stores throughout |
| spin +0x10 / clear +0x0C | yes | `ADD EAX,-1` / `MOV [ESI+0xC],EBX` |
| free elems reverse | yes | `[base+i*4-4]` then `SUB EDI,1` |
| free buffer | yes | second `operator_delete` |
| zero +8/+4 | yes | `MOV [ESI+8/4],EBX` |
| delete noreturn | warned | **continues** after `ADD ESP,4` |

**Consensus:** accept CF. Gaps on type English / element dtor policy.

---

## 4. Surviving contract for AutoCore

```csharp
// this in ESI on retail. Portable: explicit self*.
static void OwnedPtrTable_Clear(OwnedPtrTable self)
{
    while (self.LiveCount != 0)
    {
        self.LiveCount--;
        if (self.LiveCount == 0)
            self.Cached = null;
    }
    for (int i = self.Count; i > 0; )
    {
        i--;
        var p = self.Data[i];
        if (p != null) NativeDelete(p); // operator_delete only
    }
    if (self.Data != null) NativeDelete(self.Data);
    self.Count = 0;
    self.Data = null;
}
```

**Port traps to reject:**

- Treating as ECX thiscall without ESI shim.
- Skipping element deletes (buffer-only free).
- Calling typed C++ dtor not present in retail body (unless proven elsewhere).
- Trusting Ghidra noreturn (would kill control-flow analysis).

---

## 5. Residual questions

1. What writes `+0x10` / `+0x0C` in the first place?
2. Is there a matching `OwnedPtrTable_Push` / grow helper nearby?
3. Element allocation site (size / type)?
