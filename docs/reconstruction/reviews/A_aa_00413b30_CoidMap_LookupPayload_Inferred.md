# Review A (reconstruction fidelity): `aa_00413b30` CoidMap_LookupPayload (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413b30` |
| **VA** | `0x00413b30` |
| **Canonical name** | `CoidMap_LookupPayload` (**INFERRED**) |
| **Ghidra symbol** | `FUN_00413b30` |
| **Review date** | `2026-07-29` |
| **Counterpart** | `reviews/B_aa_00413b30_CoidMap_LookupPayload_Inferred.md` |
| **System** | `inventory-transfer` (Drop hit-test nested) |
| **Parent batch** | Grab/Drop/AddItem/Equip nested residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve a COID pair against a map host → return payload pointer** (or 0).

Sole call site: `Client_UI_InventoryDropHitTest` path inside `0x0085f220` family @ `0x0085f4df`:

```text
; after cell hit produces COID lo/hi in regs
cmp  edx, -1
je   no_item
push ecx / push eax          ; COID pair
mov  eax, [esi+0x570]        ; map host from inventory window
call FUN_00413b30            ; → 0x00413b30
mov  [outItemSlot], eax
```

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | map / table host | call-site `mov eax,[esi+0x570]` before CALL |
| stack0/1 | COID lo / hi | push pair; match `FUN_00419b40` walk keys at node `+0x18/+0x1c` |
| EAX out | payload or 0 | stored to hit-test out; decompiler: `*(found+0xc)` |

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | `force_decompile` `0x00413b30` + callee `0x00419b40` |
| Live bytes | `read_memory` @ `0x00413b30` — table index via `EAX+8` / `EAX+0x10` then `call 0x00419b40` |
| Call site bytes | `read_memory` @ `0x0085f4d0` — `mov eax,[esi+0x570]; call 0x00413b30` |
| Xrefs | **1** UNCONDITIONAL_CALL (`0x0085f4df`) |
| Raw | `raw/aa_00413b30_FUN_00413b30.md` |
| Parent | Drop `0x00860a50` → hit-test `0x0085f220` |

**Not performed:** `disassemble_bytes`, Launcher.

---

## 3. Control flow (bytes + callee; decompiler thinned)

Ghidra high decompile collapses to:

```c
node = FUN_00419b40(coidLo, coidHi);
return node ? *(node + 0xc) : 0;
```

**Byte residual (sealed as map host in EAX):** entry uses `[eax+8]` / `[eax+10]` + index mask before calling `FUN_00419b40`. Callee walks chain matching `node+0x18/+0x1c` to COID pair; parent returns field **`+0xc`**.

| Claim | Confidence |
|---|---|
| Hit-test uses result as item* (or 0) | **High** |
| Map host from `window+0x570` in EAX | **High** (call-site asm) |
| COID match keys at node `+0x18/+0x1c` | **High** (callee body) |
| Return payload at `+0xc` | **High** (decompile + consumer) |
| Full hash-bucket formula | **Probable** (bytes; decompiler collapsed) |

---

## 4. Gaps

1. Product name of map object at `window+0x570`.
2. Full bucket hash math (prefer bytes over collapsed decompile).
3. Whether payload `+0xc` is always `Item*` vs wrapper.
4. Runtime multi-page hit-test.

**Verdict:** **accept-with-gaps** — Drop hit-test COID→item leaf role sealed; map layout Probable.
