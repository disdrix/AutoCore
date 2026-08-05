# Review B (skeptical / adversarial): `aa_00513770` Item_IsWantedByStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513770` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/A_aa_00513770_Item_IsWantedByStore_Inferred.md` |
| **Residual scratch** | `reviews/a_00513770.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** on CF + offsets + polarity; **reject** overclaims that this unit sells, prices, or places items |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the InventoryDrop **send** / place path | Body has no packet, no `FUN_00571620`, no grid write | **Falsified** — pure gate |
| 2 | This computes sell **price** | No float/mul; sibling is `0x005142A0` | **Falsified** |
| 3 | Return is multi-byte status (`CONCAT31` meaningful) | Bytes: `setz al` / `mov al,1` only | **Falsified** — bool AL |
| 4 | `FUN_004f1e20(0,1)` is a free global call | Asm: ECX = `*(this+0xA8)` before call; stack `(0,1)` | **Falsified framing** — thiscall on clonebase |
| 5 | `this` is clonebase / def blob | Callers pass held/list **item**; body uses `+0xA8` hop | **Falsified** |
| 6 | Flag lives on clonebase (`+0x3B4` direct) | Load is `*(*(clonebase+0x3C)+0x3B4)` | **Falsified as direct** |
| 7 | Null def → reject | `mov al,1` path | **Falsified** — permissive true |
| 8 | Only one caller (DropToGrid) | 7 UNCONDITIONAL_CALL xrefs | **Falsified** |
| 9 | Wave-23 scaffold dual “sealed” quality | Scaffold only; no A/B pair existed | **Falsified** — this dual supersedes |
| 10 | Ready for bit-exact / product name seal | No runtime; name `_Inferred` | **Fail** for complete |

---

## 2. Decisive dataflow — store-want predicate (SEALED)

```text
bool __thiscall Item_IsWantedByStore_Inferred(Item* this)
{
    Clonebase* cb = *(Clonebase**)(this + 0xA8);
    if (*(void**)(cb + 0x3C) == nullptr)
        FUN_004f1e20(cb, 0, 1);          // ensure def; ECX=cb

    void* def = *(void**)(cb + 0x3C);    // re-read after ensure
    if (def == nullptr)
        return true;                     // AL=1

    return *(int32_t*)((uint8_t*)def + 0x3B4) == 1;
}
```

Live body matches 2026-07-23 raw capture (same decompiler text). Residual: `a_00513770.md`.

**Cross-seals:**

| Peer | Relation |
|------|----------|
| `Item_CanAcceptStackQty` `0x0040ABF0` | same `item+0xA8` / `+0x3C` def hop |
| `FUN_005142A0` | same ensure + `+0x3B4!=1` → 0; then price |
| DropToGrid type-4 | `AL==0` → `"The store does not want that item."` |
| `FUN_00942530` | `AL!=0` → C2S `0x2027` size `0x40` |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bool AL / plain RET | **High** | Misread multi-status |
| ECX Item* + clonebase `+0xA8` | **High** | Wrong object |
| Ensure only on null def | **High** | Spurious loads / missed loads |
| Null def → true | **High** | Over-reject unloadable items |
| `def+0x3B4 == 1` | **High** | Wrong items sellable |
| Toast polarity | **High** | Invert store UX |
| Field English “vendor buy flag” | **Probable** | Doc only |
| Product symbol | **Open** | Rename residual |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0xA8` as clonebase | Invented? | **No** — family dual `aa_0040abf0` + this body |
| Flag at `clonebase+0x3B4` | Compatible? | **No** — one more hop via `+0x3C` |
| `+0x3B4` equals customized `+0x4BE` | Same field? | **No** — different offsets; trade paths check both |
| Side-effect stores on item | Hidden? | **None** on item; ensure may fill clonebase def |
| Drop places footprint | This unit? | **No** |

---

## 5. Surviving contract for AutoCore

```text
// Client store/vendor pre-gate (type-4 drop / sell UI / bulk sell):
if (!Item_IsWantedByStore(item)) {
    toast("The store does not want that item.");
    return;
}
// then price (005142a0) and/or C2S 0x2027 / store packet path

// Semantics:
//   def missing after ensure → allow (true)
//   def present → require *(i32*)(def + 0x3B4) == 1
```

Do **not** conflate with:

- stack capacity (`Item_CanAcceptStackQty`)
- stack eligibility / Broken (`FUN_00513E70` family)
- trade customized bit (`def+0x4BE`)
- grid place / DropResponse

---

## 6. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Product name / PDB | No for port (use `_Inferred`) |
| R2 | `FUN_004f1e20` English + full side effects | Mild — role sealed as ensure |
| R3 | Runtime toast on `+0x3B4≠1` | **Yes** for complete / bit-exact |
| R4 | Why null-def is true (fail-open) | Doc only |
| ~~R5~~ | CF + offsets + polarity | **Sealed** this dual |

---

## 7. Verdict

**accept-with-gaps.** Adversarial pass falsifies sell/price/place/CONCAT overclaims; seals the store-want bool leaf. Not complete (runtime + product name open).
