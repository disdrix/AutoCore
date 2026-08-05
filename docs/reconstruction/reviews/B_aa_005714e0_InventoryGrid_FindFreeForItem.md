# Review B (skeptical / adversarial): `aa_005714e0` InventoryGrid_FindFreeForItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005714e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005714e0_InventoryGrid_FindFreeForItem.md` |
| **Residual scratch** | `reviews/a_005714e0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on CF + FindFree relation; **reject** overclaims that this unit places items or is “just FindFreeSlot” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is bare FindFreeSlot | **Falsified** — type-4 + optional stack merge before tail call |
| 2 | `this` is the item | **Falsified** — prologue `mov ebx,ecx`; call sites load **grid** into ECX; item is stack0 |
| 3 | Places / stamps footprint | **Falsified** — outs only; place is `0x00571620` |
| 4 | Always scans free cells | **Falsified** — type-4 and stack hit skip FindFree entirely |
| 5 | pageIndex ignored | **Falsified** — pushed through to FindFreeSlot |
| 6 | Stack path always runs | **Falsified** — gated by `allowStackMerge != 0` |
| 7 | Mission HandleButton proves full inventory model | **Overstated** — one caller with `1,-1`; space check only |
| 8 | Type 4 “is currency” | **Unproven** — only CF `==4` → (0,0); name interpretive |
| 9 | `FUN_005714e0` name from Unequip plate is complete | **Overstated** — also SerializeAddItem, HandleButton, drag, vendor, … |
| 10 | Ready for bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow — sealed wrapper contract

```
thiscall (ECX = InventoryGrid*), ret 0x14

if !item: return 0
if type(item)==4: *outX=*outY=0; return 1

if allowStackMerge:
  if stack_eligible(item) and peer=find_same_cbid_with_room(grid, item):
    *outX,*outY = peer.gridXY; return 1

// TAIL — sealed identity with FindFreeSlot:
return FindFreeSlot(this,
                    InvSizeX(item), InvSizeY(item),
                    outX, outY, pageIndex)
```

**Asm seals (not decompiler-only):**

- Entry: `mov ebx, ecx` then `mov esi, [esp+0xc]` (item).
- Type-4: write outs zero, `mov al,1`, `ret 0x14`.
- Fallthrough: load InvSizeY/X from `[*(item+0xa8)+0x3c]+0x407/406`, push args, **`mov ecx, ebx`**, **`call 0x005713a0`**.

---

## 3. Relation attack: “is FindFreeSlot duplicated?”

**No.** Body size ~0xEC; no Y/X scan, no cell index math, no CanPlace call. Single external first-fit is the tail call. Any bug in scan formula is owned by `aa_005713a0`, not this unit.

**Wrapper can still disagree with “grid full” intuition:**

- Type 4 → success even if grid full.
- Stack merge → success when peer has capacity even if no free rect.

HandleButton full-inventory string fires only when this returns 0 — so stack-full **and** no free rect **and** not type-4.

---

## 4. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX = grid thiscall | **High** | Wrong owner for FindFree/peer |
| Tail = FindFreeSlot | **High** | Invented reimplementation |
| InvSize from +0x406/407 | **High** | Wrong footprint |
| page passthrough | **High** | Page-restricted loot wrong |
| Type-4 bypass | **High** CF | False “needs space” |
| Stack merge optional | **High** CF | Force free-rect only |
| Type-4 taxonomy | **Tentative** | Wrong server mirror |
| All callers use page=-1 | **High sampled / not exhaustive** | Miss page window |
| Runtime parity | **Open** | Residual risk |

---

## 5. Surviving contract for AutoCore

```
FindSpaceForItem(grid, item, allowStack, page=-1) ≈ client 0x005714e0:
  if item.typeClass == 4: origin (0,0) ok
  if allowStack and can merge onto peer: origin = peer.xy ok
  else TryFindFirstFree(grid, item.InvSizeX, item.InvSizeY, page)

Does not PlaceItemFootprint.
```

Server already has `TryFindFirstFree` for the fallthrough; stack merge + type-4 short-circuit must be modeled **outside** that helper if client parity is required for reward/add/unequip checks.

---

## 6. Verdict

### **accept-with-gaps**

**Accept CF + sealed FindFreeSlot relation** under dual A + residual + memory seals.

**Reject** equating this VA with FindFreeSlot alone, item-as-this, or place/stamp.

**Gaps:** type-4 product class, exhaustive caller page args, stack helper dual depth, runtime.
