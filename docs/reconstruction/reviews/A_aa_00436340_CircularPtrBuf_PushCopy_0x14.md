# Review A (reconstruction fidelity): `aa_00436340` CircularPtrBuf_PushCopy_0x14 (inferred)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436340` |
| **VA** | `0x00436340` |
| **Body span** | `00436340` – `004363aa` |
| **Canonical name** | `FUN_00436340` retained; role **`CircularPtrBuf_PushCopy_0x14`** (**Inferred**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory` of body) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_00436340_CircularPtrBuf_PushCopy_0x14.md` |
| **System** | container / circular pointer-buffer utility |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Push** a caller-supplied **0x14-byte POD** into a **circular buffer of heap element pointers**:

1. **Buffer `this`** in **EAX**.
2. **Source struct** in **EDI** (exactly **five dwords**).
3. If **`capacity <= count + 1`**, grow via **`FUN_00436650(1)`** (EBX=`this`).
4. **`writeIndex = head + count`**, wrap if `capacity <= writeIndex`.
5. If **`slots[writeIndex] == 0`**, **`operator_new(0x14)`** and store.
6. If element pointer non-null, **copy 5 dwords** from EDI.
7. **`count++`** always (even if element still null after alloc).

No product string on this VA — multi-domain utility (leave `FUN_*`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00436340_FUN_00436340.md` |
| Annotated | `docs/reconstruction/raw/aa_00436340_FUN_00436340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00436340.cpp` |
| Function record | `docs/reconstruction/functions/aa_00436340_FUN_00436340.md` |

**This pass (live, OWN VA only):**

- Ghidra MCP `decompile_function` @ `0x00436340` — matches 2026-07-23 plate (`in_EAX`, `unaff_EDI`).
- Ghidra MCP `read_memory` @ `0x00436340` length 128 — body ends `5B C3` at `0x004363aa`; grow `E8` → `FUN_00436650`; `push 0x14` + `operator_new`.
- Ghidra MCP `decompile_function` @ `0x00436650` — residual grow (circular rearrange of pointer array using EBX); used only to confirm “capacity grow” role.
- **Not performed:** Launcher, runtime golden, bit-exact diff; **no ownership** of `0x00436650` or `operator_new`.

---

## 3. Calling convention (assembly-sealed on OWN body)

| Slot | Role | Evidence |
|---|---|---|
| **EAX** | buffer object `this` | prologue `mov ebx, eax` then all field ops via EBX |
| **EDI** | `const uint32_t src[5]` | five loads `[edi]`…`[edi+0x10]` |
| **Stack** | none | plain `ret` |
| **Return** | void | fall-through `pop ebx; ret` |

Ghidra plate `void FUN_00436340(void)` with `in_EAX` / `unaff_EDI` is **behaviorally correct**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `00436340`–`004363aa`, plain `ret` | **High** | `read_memory` |
| this EAX; source EDI | **High** | Own body |
| `+0x04` slots, `+0x08` capacity, `+0x0c` head, `+0x10` count | **High** | Field uses |
| Grow when `capacity <= count+1` | **High** | `lea/add` count+1; `cmp [ebx+8],eax`; `jbe`-equivalent `ja` skip |
| Write index `(head+count) % capacity` | **High** | add + conditional sub |
| Lazy `new(0x14)` on null slot | **High** | `push 14h` |
| 5-dword POD copy | **High** | five mov pairs |
| `count++` always | **High** | after optional copy |
| Null after failed new → skip copy, still inc | **High CF** | `test eax; jz inc` |
| Product container / element type names | **Low–Tentative** | no string |
| Clean ≡ raw decompiler CF | **High** | scaffold aligned to live plate |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 5. Control flow checklist (clean ≡ raw ≡ live)

| Stage | Match |
|---|---|
| Grow gate `capacity <= count+1` → `FUN_00436650(1)` | **Yes** |
| `writeIndex = head + count`; wrap subtract capacity | **Yes** |
| Null slot → `operator_new(0x14)` store | **Yes** |
| Non-null → copy dwords 0..4 from EDI | **Yes** |
| Null → skip copy | **Yes** |
| `count += 1` | **Yes** |
| No invent pop/erase/destructor | **Yes** |

```text
PushCopy20(buf EAX, src EDI):
  if buf.capacity <= buf.count + 1:
    grow(buf, 1)                 // FUN_00436650
  i = buf.head + buf.count
  if buf.capacity <= i: i -= buf.capacity
  if buf.slots[i] == null:
    buf.slots[i] = new (0x14)
  if buf.slots[i] != null:
    memcpy_pod20(buf.slots[i], src)
  buf.count++
```

---

## 6. Buffer field map (this unit only)

| Offset | Role in this function | Confidence |
|---|---|---|
| `+0x04` | base of pointer array | **High** |
| `+0x08` | capacity (elements) | **High** |
| `+0x0c` | head index | **High** |
| `+0x10` | live count | **High** |

---

## 7. Gaps

1. **Product / STL symbol** for the container unknown (custom ring vs game queue).
2. **Element type** of the 0x14-byte POD — requires caller dual (out of scope).
3. **`FUN_00436650`** growth/reindex math residual — ports must either dual that VA or treat grow as opaque.
4. Counted-null after OOM: intentional soft-fail vs unreachable.
5. Runtime / differential **Open**.

**Verdict:** **accept-with-gaps** — CF and ABI sealed High for AutoCore circular push-copy; leave product names open; grow callee residual.
