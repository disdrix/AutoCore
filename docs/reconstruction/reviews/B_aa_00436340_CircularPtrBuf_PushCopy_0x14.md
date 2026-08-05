# Review B (skeptical / adversarial): `FUN_00436340` @ `0x00436340`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436340` |
| **VA** | `0x00436340` |
| **Body span** | `00436340` – `004363aa` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_00436340_CircularPtrBuf_PushCopy_0x14.md` |
| **System** | container / circular pointer-buffer utility |
| **Verdict** | **accept-with-gaps** on OWN CF/ABI; **needs-more-evidence** on product type names and grow callee |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is a normal `std::vector::push_back` of values | **Falsified** — stores **pointers** to heap **0x14** blobs; uses **head+count** modular write (ring), not end-pointer vector |
| 2 | `this` is ECX (`__thiscall`) | **Falsified** — **`this` is EAX** (`mov ebx,eax`); grow callee also takes **EBX** |
| 3 | Source is a stack argument | **Falsified** — source is **EDI** (`unaff_EDI`) |
| 4 | Grow when full (`count == capacity`) | **Overstated** — grows when **`capacity <= count+1`** (keeps ≥1 free slot after push) |
| 5 | Always constructs a new element | **Falsified** — **reuses** existing non-null slot pointer; only `new` on null |
| 6 | OOM aborts / does not advance count | **Falsified** — null after new → **skip copy** but **`count++` still runs** |
| 7 | Element has constructors (non-POD) | **Overstated** — pure 5× dword mov; no ctor/dtor calls |
| 8 | Inferred name is product-accurate | **Unproven** — descriptive only; leave `FUN_00436340` |
| 9 | Runtime verified | **Falsified** — open / deferred |
| 10 | Scaffold clean was modernized-safe | **Overstated** — CF scaffold of decompiler; not bit-exact EXE proof |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX this / EDI src / void ret | **High** | Total call corruption |
| Layout `+4/+8/+c/+10` | **High** | Wrong capacity/head → wrap OOB |
| Modular write index | **High** | Overwrite wrong slot / linear overflow |
| Grow threshold `capacity <= count+1` | **High** | Ports that grow only at full may overflow ring |
| Lazy `new(0x14)` + 5-dword copy | **High** | Size mismatch corrupts heap |
| Counted-null on OOM | **High CF** | Ports that assume non-null after push diverge |
| Product type / domain | **Low** | Wrong subsystem placement only |
| Grow body `FUN_00436650` | **Out of scope** | Dual OWN-only |
| Clean ≡ raw decompiler CF | **High** | Safe as map |

---

## 3. Surviving contract for AutoCore

```
// this: EAX; src: EDI (0x14 POD); void
CircularPtrBuf_PushCopy_0x14(buf, src):
  if buf.capacity <= buf.count + 1:
    FUN_00436650(1)              // this in EBX
  i = buf.head + buf.count
  if buf.capacity <= i:
    i -= buf.capacity
  if buf.slots[i] == 0:
    buf.slots[i] = operator_new(0x14)
  if buf.slots[i] != 0:
    copy 5 dwords src → slots[i]
  buf.count += 1
```

**Port rules that survive adversarial review:**

1. Pass **this in EAX**, **source in EDI** — not ECX/stack unless a wrapper reloads.
2. Preserve **lazy reuse** of existing element heap nodes (overwrite POD, no free).
3. Grow **before** the buffer would leave zero free slots (`<= count+1`), not only at exact full.
4. Do not assume non-null element after push if `operator_new` can fail.
5. Treat element as **raw 20-byte POD** until a caller dual names the struct.

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs `raw/aa_00436340_*.md` plate | **Match** |
| Clean vs raw CF stages | **Match** |
| Annotated asm vs `read_memory` | **Match** |
| `unaff_EDI` / `in_EAX` as real ABI | **Sealed** by own body (not Ghidra fiction) |

---

## 5. Open questions (OWN residual only)

1. Product name of buffer + 0x14 element (caller dual required).
2. Whether `FUN_00436650` can fail / throw / never-return paths affect this push.
3. Whether any caller relies on pre-existing slot contents when reusing non-null pointers (partial overwrite of only 0x14 — full replace of five dwords).
4. Runtime not run.

**Verdict:** **accept-with-gaps** on OWN control flow, register contract, layout, and copy size; **needs-more-evidence** before product STL/game type names or treating grow as fully specified. Safe behavioral map for AutoCore circular 0x14 push-copy once ABI and soft-null rules are honored.
