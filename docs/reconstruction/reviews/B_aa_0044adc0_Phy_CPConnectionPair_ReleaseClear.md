# Review B (skeptical / adversarial): `aa_0044adc0` Phy_CPConnectionPair_ReleaseClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044adc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0044adc0_Phy_CPConnectionPair_ReleaseClear.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This `delete`s the pair heap object | No `operator_delete`; only slot clears + Release | **Falsified** free claim |
| 2 | Plain cdecl / void decompiler ABI | Bytes `ret 4` | **Over-narrow** — stdcall |
| 3 | Releases only one COM pointer | Two slots `+4` and `+0xC` | **Falsified** single-slot claim |
| 4 | `+0` / `+8` are also COM and get Release | Only stores 0; no ref protocol | **Falsified** — raw outs |
| 5 | Name must be ClientSpecialEvent-specific | Also called from pair-bind UI/physics paths; layout matches `0x0044af00` | **Survives** CP pair role |
| 6 | `FUN_00437150` always releases again | Slots already 0 → helper no-op path | **Overstated** second release — CF still calls it |
| 7 | `vtbl+8` is definitely IUnknown::Release | Protocol matches; English not plate-proven here | **Probable** only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual release + clear order | **High** | Leaks / double-free |
| Stdcall `ret 4` | **High** | Stack corruption in ports |
| Layout +0/+4/+8/+0xC | **High** | Wrong teardown in attach fail |
| CP-connection product family | **High** (sibling strings/layout) | Mis-system placement |
| Exact type / vtbl names | **Probable** | Docs only |

---

## 3. Cross-check against raw / bytes

```
raw: clear +8; release +0xC; clear +0; release +4; FUN_00437150×2
bytes: mov [esi+8],0; ... add [ecx+4],-1; call [eax+8]; ... ret 4
```

Clean ≡ raw ≡ bytes. No modernization of CF.

---

## 4. Surviving contract for AutoCore

```csharp
// Pair block is NOT freed here — caller deletes if needed
static void ReleaseClearPair(CPConnectionPair pair)
{
    pair.OwnerOut1 = null;
    ReleaseRefSlot(ref pair.SmartB); // +0xC
    pair.OwnerOut0 = null;
    ReleaseRefSlot(ref pair.SmartA); // +4
    // retail also calls FUN_00437150 on both slots (no-op if null)
}

static void ReleaseRefSlot(ref RefCountedLike? slot)
{
    if (slot == null) return;
    if (--slot.RefCount == 0)
        slot.VtableRelease(); // vtbl+8
    slot = null;
}
```

**Port traps to reject:**

- Freeing the pair inside this function.
- cdecl without stack cleanup (`ret 4` required).
- Releasing `+0`/`+8` as COM.
- Skipping either smart slot.

---

## 5. Residual gaps (do not block seal)

1. Live attach-fail differential.  
2. `FUN_00437150` dual residual (owned elsewhere).  
3. Product spelling of pair typedef.

---

## Verdict

**accept** — adversarial review cannot break the dual-slot Release/clear + stdcall contract. Main falsifications are “this deletes the block” and “cdecl void only.”
