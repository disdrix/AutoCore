# Review A (reconstruction fidelity): `aa_00931870` Inventory_WriteSwapDebugLog

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931870` |
| **VA** | `0x00931870`–`0x00931a46` (image through `ret 0x1c`; Ghidra body stamp ends early at `0x009319f6`) |
| **Canonical name** | `Inventory_WriteSwapDebugLog` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + image) |
| **Counterpart** | `reviews/B_aa_00931870_Inventory_WriteSwapDebugLog.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present — CF + strings + list free sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **debug-only** helper: open/append `InventoryLog.txt`, write a **Before Swap** or **After Swap** banner, dump every item in two temporary **item\* lists** as `coid` + `quantity`, close the file, then **destroy both lists** (nodes + head sentinels).

Naming is string-backed (`InventoryLog.txt`, `-----Before Swap-----`, `\n-----After Swap-----`, `\ncoid: %I64d \nquantity: %d`). Sole live caller is `FUN_00955010` (cargo↔locker random-swap / organize path) at two sites:

| Site | Role |
|---|---|
| `0x00955139` | Pre-swap dump (`isAfter == 0`) |
| `0x00955d7d` | Post-swap dump (`isAfter != 0`) |

Each site **copy-constructs** two 12-byte list temps (`FUN_00402410` ×2, `SUB ESP,0xC` each) then `CALL` this unit.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00931870_FUN_00931870.md` |
| Annotated | `docs/reconstruction/raw/aa_00931870_FUN_00931870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inventory_WriteSwapDebugLog.cpp` |
| Function record | `docs/reconstruction/functions/aa_00931870_Inventory_WriteSwapDebugLog.md` |
| Fresh decompile | Ghidra `decompile_function` + `force_decompile` @ `0x00931870` (2026-07-29) — **3 reps identical** |
| Body image | Ghidra `read_memory` entry / item loop / dual free / epilogue |
| Call-site asm | `get_assembly_context` on both xrefs |
| Callees | `fopen` / `fprintf` / `fclose` (IAT), `FUN_00404060` (list clear), `operator_delete` |
| Related offsets | Item COID / qty vtbl sealed in inventory duals (`+0x160/+0x164`, vtbl `+0x25c`) |

**Not performed:** `disassemble_bytes` as primary, Launcher, runtime `InventoryLog.txt` capture, binary diff.

---

## 3. Signature (assembly-sealed)

```c
// __stdcall — epilogue: ADD ESP,0xC (SEH frame); RET 0x1C  (28 bytes of args)
// Two MSVC-style 12-byte list objects by value + char flag in a 4-byte slot.
void __stdcall Inventory_WriteSwapDebugLog(
    List12 listA,       // +0 base, +4 head*, +8 size  (first stack object)
    List12 listB,       // same layout (second stack object)
    char   isAfterSwap  // 0 → "-----Before Swap-----"; nonzero → "\n-----After Swap-----"
);
```

Expanded (matches decompiler param slots):

| Stack (after `ret`) | Decomp name | Role |
|---|---|---|
| `+0x04` | `param_1` | `listA+0` |
| `+0x08` | `param_2` | `listA+4` = **head sentinel\*** (walk / free) |
| `+0x0c` | `param_3` | `listA+8` = size |
| `+0x10` | `param_4` | `listB+0` |
| `+0x14` | `param_5` | `listB+4` = **head sentinel\*** |
| `+0x18` | `param_6` | `listB+8` = size |
| `+0x1c` | `param_7` | `isAfterSwap` (byte tested) |

| Claim | Evidence | Confidence |
|---|---|---|
| `__stdcall` + `RET 0x1C` | Epilogue `C2 1C 00` @ `0x00931a44` | **High / Confirmed** |
| Two 12-byte list values | Call sites `SUB ESP,0xC` ×2 + `FUN_00402410`; fail path `LEA ECX,[ESP+0x20]` → `FUN_00404060` | **High / Confirmed** |
| List layout `head@+4`, `size@+8` | `FUN_00404060` / `FUN_00402410`; fail path `MOV EAX,[ESP+0x24]` then `operator_delete` | **High / Confirmed** |
| Flag 0 = Before, else After | `CMP byte [ESP+…],0` → push `0x00a2c3ec` vs `0x00a2c3d4` | **High / Confirmed** |
| Void / no useful return | No EAX setup before `ret 0x1c` | **High** |

---

## 4. Control flow (sealed)

```
SEH prolog (handler LAB_009ad34d); state = owning lists

fp = fopen("InventoryLog.txt", "at")          // mode @ 0x00a2c41c
if (!fp) {
  fp = fopen("InventoryLog.txt", "wt+")      // mode @ 0x00a2c404
  if (!fp) {
    // SEH state clear; FUN_00404060(&listA); operator_delete(listA.head); … (unwind)
  }
}

fprintf(fp, isAfter ? "\n-----After Swap-----" : "-----Before Swap-----");

// Walk listA (circular doubly-linked; head is sentinel)
for (node = headA->next; node != headA; node = node->next) {
  item = node[2];                            // +0x08 payload
  if (item) {
    coid_lo = item[+0x160];                  // dword index 0x58
    coid_hi = item[+0x164];                  // dword index 0x59
    qty     = (*item->vtbl[+0x25c])(item);   // thiscall qty getter
    fprintf(fp, "\ncoid: %I64d \nquantity: %d", coid_lo, coid_hi, qty);
  }
}

// Walk listB — identical body
for (node = headB->next; node != headB; node = node->next) { … same dump … }

fclose(fp);

// Destroy listA: empty head links; size=0; free every node; free head sentinel; head*=0
// Destroy listB: same (EDI = headB)          ← DECOMPILER DROPS THIS (see hazards)
// SEH teardown; ret 0x1c
```

### Node / item geometry (this unit)

```
List object (12 B, by value on stack)
  +0x00  base / unused in this body
  +0x04  head*   (sentinel node)
  +0x08  size

List node
  +0x00  next*
  +0x04  prev*
  +0x08  item*   (may be null — skipped)

Item (payload)
  +0x00  vtbl*
  +0x160 / +0x164  COID lo/hi  (fprintf as single %I64d)
  vtbl[+0x25c]     quantity getter (thiscall; result pushed as %d)
```

COID / qty offsets match inventory family (`Inventory_SerializeAddItemPacket`, `Client_SendInventoryAddItem`, `Item_CanAcceptStackQty`).

---

## 5. Decompiler hazards corrected

| Decomp artifact | Reality (image) |
|---|---|
| Function body ends @ `0x009319f6` after first `operator_delete` | Continues through **listB free** + SEH + **`ret 0x1c`** @ `0x00931a44` |
| `/* does not return */ operator_delete` on free loop | False — free is a **loop** (`ADD ESP,4; CMP; JNZ`); then delete head; then listB |
| Only `param_2` list destroyed | **Both** heads (`EBX`=listA, `EDI`=listB) fully freed |
| `void` vs `undefined` return | **void** / no return value — ignore “verify EAX” completeness nag |
| Seven `undefined4` params as independent scalars | Two **12-byte list values** + flag; heads are `list+4` |
| fopen-fail `operator_delete(param_2)` only | Fail path: `FUN_00404060(&listA)` then `delete(listA.head)` (SEH partial unwind) |

### Stack-window note (item loop)

Item `fprintf` pushes **5** args (`ADD ESP,0x14` after). While args are live, `[ESP+0x38]` aliases the **listA head stack slot** (`listA+4`); the second loop’s `MOV EBX,[ESP+0x38]` **reloads listA head** after using `EBX` as COID hi — not an iterator restore. Iterator lives at a higher slot and is reloaded via `[ESP+0x4c]` under the same window.

---

## 6. Strings / modes (read_memory)

| VA | Content |
|---|---|
| `0x00a2c408` | `InventoryLog.txt` |
| `0x00a2c41c` | `at` |
| `0x00a2c404` | `wt+` |
| `0x00a2c3ec` | `-----Before Swap-----` |
| `0x00a2c3d4` | `\n-----After Swap-----` |
| `0x00a2c3b8` | `\ncoid: %I64d \nquantity: %d` |

Open policy: try **append** (`at`); if that fails, create/truncate (`wt+`). Both fail → list unwind, no log.

---

## 7. Callees (roles)

| Target | Role |
|---|---|
| `fopen` / `fprintf` / `fclose` | File I/O via IAT (`PTR_*_009c66xx`) |
| `FUN_00404060` | List clear (head self-link, size 0, free nodes) — fail path |
| `operator_delete` (`0x00489822`) | Free list nodes + head sentinels |
| `vtbl+0x25c` | Item quantity (indirect) |
| `LAB_009ad34d` | SEH handler for owned stack lists |

Copy helper used only at **call sites** (not inside this body): `FUN_00402410` (list copy-construct).

---

## 8. Three-rep decompile

| Rep | Method | Result |
|---|---|---|
| 1 | `decompile_function` | Body as in raw (truncates after listA free) |
| 2 | `force_decompile` | **Identical** |
| 3 | `decompile_function` | **Identical** |

No decompiler disagreement — residual is **Ghidra function-end / noreturn**, corrected from image, not from multi-rep conflict. No separate three-rep transcript file required.

---

## 9. Gaps / open questions

1. Product English for sole caller `FUN_00955010` (swap/organize between cargo grid `+0x2b0` and locker `+0xcbc` — out of OWN scope).
2. Whether `listA`/`listB` order is always (cargo, locker) vs (source, dest) at both call sites (caller-owned).
3. `list+0` field role (allocator/base) — unused in this body.
4. Runtime: confirm `InventoryLog.txt` lines under a live swap (not run this dual).
5. Clean C++ scaffold still uses decompiler param names / truncated free — dual supersedes for contract.

---

## 10. Verdict

### **accept-with-gaps**

Control flow, strings, `__stdcall ret 0x1c`, dual-list walk dump, COID/qty field use, and **both-list destroy** are **sealed** from decompile + image. Gaps are caller product naming, list-order English, and runtime log capture. AutoCore does **not** need this for correctness (debug log only); keep as inventory diagnostics reference.
