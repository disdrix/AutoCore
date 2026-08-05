# Review B (skeptical / adversarial): `FUN_008aa560` @ `0x008aa560`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa560` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` |
| **Verdict** | **accept-with-gaps** on clear loop + EBX ABI + offsets; **needs-more-evidence** on product names and TFID pair English |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `unaff_EBX` is decompiler junk | Caller `MOV EBX,EDI` immediately before CALL; all LEAs use EBX | **Falsified** — EBX is deliberate ABI |
| 2 | Loop count comes from `dialog+0x510` | Bytes hardcode `mov ebp,8`; no load of +0x510 | **Falsified** — fixed 8 |
| 3 | This rebuilds buttons | No `operator_new`, no XML load; only destroy/clear | **Falsified** — clear-only; rebuild is caller |
| 4 | Clears reward chrome at +0x698 | Offsets sealed +0x518 / +0x708 only | **Falsified** as reward wipe |
| 5 | vtbl+0xBC is AppendText | Ordinal 0xBC ≠ 0x250; used with non-null widget free pattern | **Falsified AppendText** — destroy/release pattern |
| 6 | Multiple callers | xrefs count 1 | **Survives sole caller** |
| 7 | Stack args exist | plain `RET` (`C3`), no `RET imm16`; no pushes of formals | **Falsified stack formals** |
| 8 | Scaffold callee-of-xml name is product | Auto plate from parent XML string | **Demote** to alias only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX dialog this | **High** | Wrong object wiped |
| 8 slots + strides | **High** | Partial leak of old buttons |
| +0x518 / +0x708 | **High** | Wrong banks |
| Destroy ordinal +0xBC | **High** role | UI leak if wrong |
| Pre-rebuild ordering | **High** | Caller decompile places CALL first |
| Product names | **Open** | Registry noise |
| TFID pair meaning | **Tentative** | Wrong HandleButton index mapping if misread |

---

## 3. Cross-check spine

```
// EBX = dialog
widgets = dialog+0x708
tfids   = dialog+0x518
for i in 0..7:
  tfids[i] = {-1,-1}
  if widgets[i]:
    dialog->vtbl[0xBC](widgets[i])
    widgets[i] = 0
```

### What this unit is **not**

| Non-claim | Why |
|---|---|
| Reward chrome (`FUN_008aa760`) | different banks +0x558/+0x698 |
| Markup paint (`FUN_008aab00`) | no strings/tags |
| Button click / HandleButton | no input path |
| Packet send | no sector send |

---

## 4. Residual attacks left open

1. Is capacity always 8 or could image variants use different count? (This binary: hardcoded 8.)
2. Does vtbl+0xBC free memory or only detach from parent? (Both are “destroy chrome” for port purposes; exact allocator open.)
3. Are TFID pairs mission-keys, response-ids, or object COIDs? External consumers needed.

---

## 5. Verdict

**accept-with-gaps** — adversarial pass cannot break the 8-slot clear, EBX ABI, or offset map; product English and TFID semantics remain open. No runtime Confirmed.
