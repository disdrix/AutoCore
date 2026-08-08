# Review B (skeptical / adversarial): `aa_0092a3d0` Tracker_ClearOwnedPtrVectorAt11c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a3d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-088) |
| **Counterpart** | `reviews/A_aa_0092a3d0_Tracker_ClearOwnedPtrVectorAt11c_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is full tracker dtor | **Falsified** — only clears vector at `+0x11c`; host survives; no vtbl/SEH teardown |
| 2 | Frees the vector buffer | **Falsified** — buffer free is sibling `FUN_0092a600` after this returns; this only sets `end:=begin` |
| 3 | Deletes only the first element | **Falsified** — bytes loop `ADD ESI,4` / `JNZ 0x0092a3e0` over full `[begin,end)` |
| 4 | `operator_delete` is noreturn | **Falsified** — `ADD ESP,4` then loop/compare continues; decompiler warning is wrong |
| 5 | ECX-thiscall | **Falsified** — body uses **EDI**; callers explicitly `MOV EDI,ECX` / stack / EAX→EDI before call |
| 6 | cdecl stack this / stack args | **Falsified** — bare `RET` (no `RET n`); no stack loads of this |
| 7 | Returns void / failure possible | **Falsified** — `MOV AL,1` only exit; always success |
| 8 | Scaffold Nested MissionDial name is product | **Falsified** — no strings in body; role from tracker vector clear + parent binder, not dialog button |
| 9 | Element type is mission-dialog widget | **Unsupported** — no type evidence in body; open gap (not claimed as sealed) |
| 10 | Same as `FUN_0092a600` | **Falsified** — 600 free+zeros capacity triple after calling this |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EDI-host / bare RET / AL=1 | **High** | Wrong call convention / stack smash |
| Delete loop over full range | **High** | Leak of later elements |
| end:=begin without free buffer | **High** | Double-free if merged with 600 |
| Offsets +0x11c / +0x120 | **High** | Wrong layout port |
| Product English of `T*` | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

- Live 2026-08-05 decompile ≡ 2026-07-23 raw CF (both loop-collapsed).  
- `read_memory` 110 B seals loop bytes decompiler omitted.  
- Call-site asm seals EDI setup on all 5 xrefs.  
- Sibling `FUN_0092a600` disasm: call this → `operator_delete([EDI+0x11c])` → zero `+0x11c/120/124` → `RET 4`.

---

## 4. Surviving contract for AutoCore

```
// Custom EDI-this clear of owned pointer vector at tracker+0x11c:
AL = Tracker_ClearOwnedPtrVectorAt11c_Inferred(tracker /*EDI*/);  // AL always 1
// Do NOT free buffer here. Pair destroy: FUN_0092a600(tracker) free+zeros.
// Callers of binder FUN_0092a590 set EDI=ECX before invoking this.
```

---

## 5. Verdict

Adversarial attacks on dtor/buffer-free/single-delete/ECX-this/scaffold-product claims fail. Residual product element type only → **accept-with-gaps**. Terminal **false**.
