# Review B (skeptical / adversarial): `aa_00531570` CVOGCharacter_TryType1aSimpleExchange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ8R-B) |
| **Counterpart** | `reviews/A_aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** on CF + dual-grid ECX; **reject** overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler two identical `CountItemsByCbid(cbid,0)` means double-count same grid | **Falsified** — bytes: first ECX=cargo `ebx`, second ECX=locker `ebp` |
| 2 | FindFree runs on locker / whole character | **Falsified** — `mov ecx, ebx` cargo only |
| 3 | This unit stamps footprint cells | **Falsified** — FindFree probe only; grant via `FUN_005310a0` |
| 4 | `object+0x34` is COID / TFID | **Overstated** — used as give CBID; not re-proven as TFID layout |
| 5 | Type `0x1a` product name is "recipe" / "blueprint" | **Unproven** — CF-only; keep `_Inferred` |
| 6 | Scaffold clean (2026-07-23) already dual-sealed | **Falsified** — FUN paste only; this dual supersedes |
| 7 | Ready for Confirmed runtime | **Fail** — no Launcher / CE this pass |
| 8 | Remove always clears both grids fully | **Nuanced** — second remove only if remainder `>0` after cargo |

---

## 2. Decisive evidence

### Dual-grid count (SEALED)

```
mov ebx, [cargoHolder+0x2b0]   ; cargo
mov ebp, [character+0xcbc]     ; locker
...
mov ecx, ebx
call InventoryGrid_CountItemsByCbid   ; cargo
mov edi, eax
...
mov ecx, ebp
call InventoryGrid_CountItemsByCbid   ; locker
add eax, edi
cmp vs requestQty
```

### FindFree page (SEALED)

`push 0xFFFFFFFF` (`6a ff`) before FindFree — whole-grid; matches residual caller table on `aa_005713a0`.

### Give ABI (SEALED at call boundary)

`FUN_005310a0` epilogue `ret 8` → two stack dwords; call site pushes `(outCbid, outCount)`. Body of give helper uses first stack as CBID into `CVOGReaction_GiveItemByCbid` (cross-check UseItem/Deliver call sites).

---

## 3. Residual gaps (do not block accept-with-gaps)

1. Static callers absent — do not invent vtable index without pointer scan.
2. Type `0x1a` English / data schema beyond offsets used here.
3. Partial remove if locker also short after cargo (client may leave shortfall; CF does not re-check).
4. Interaction with Broken stacks: Count/Remove use includeBroken **0** / existing Remove dual semantics.

---

## 4. Verdict

Path A fidelity holds once ECX is restored from bytes. Adversarial review **accepts** control flow and dual-grid model; **rejects** product naming and place/stamp claims.

**accept-with-gaps.**
