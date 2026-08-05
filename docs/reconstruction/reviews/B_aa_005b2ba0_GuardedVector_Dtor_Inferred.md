# Review B (skeptical / adversarial): `aa_005b2ba0` GuardedVector_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2ba0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-D) |
| **Counterpart** | `reviews/A_aa_005b2ba0_GuardedVector_Dtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | EAX = container (like PopFront/PushBack) | **Falsified** — `MOV ESI,ECX`; all offsets off ESI |
| 2 | Frees the GuardedVectorHeader heap object | **Falsified** — never `delete this`; only pages + map |
| 3 | Walks `size` pages not `capacity` | **Falsified** — second loop loads `[ESI+0x08]` (capacity) |
| 4 | Runs per-element destructor | **Falsified** — only `operator_delete` on page pointers |
| 5 | Decompiler complete on non-null map path | **Partially true attack** — decompiler drops `capacity=pages=0` after map delete; **bytes always write both** |
| 6 | CS-guarded | **Falsified** — no Enter/Leave |
| 7 | Product name retail | **Overstated** — `GuardedVector_Dtor_Inferred` structural |
| 8 | Same as `GuardedVector_ClearAndSwap` / Resize(0) | **Falsified** — ClearAndSwap swaps under CS; Resize shrink uses EraseRange; this frees pages + map |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + plain RET | **High** | Wrong ABI port |
| size drain + begin clear | **High** | Ghost begin index |
| page free by capacity | **High** | Leak / double-free |
| always zero map+capacity | **High** (bytes) | Stale pointer if trust decompile only |
| No element dtor | **High** | Leak of owning elements if callers assume it |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Residual |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  drain +0x10; on 0 clear +0x0c
  for capacity..: delete pages[i-1]
  if pages: delete pages
  // decompiler: early return path zeros +8/+4; non-null path appears to stop at delete

bytes (102 B):
  MOV ESI,ECX; XOR EBX,EBX
  size loop with optional begin=0
  capacity loop: MOV EAX,[ESI+4]; MOV EAX,[EAX+EDI*4-4]; conditional delete
  load pages; POP EDI; JE skip_delete_map
  delete pages
  MOV [ESI+8],EBX; MOV [ESI+4],EBX   ; ALWAYS
  POP ESI; POP EBX; RET
```

Both `E8` rel32 targets resolve to **`0x00489822`** (`operator_delete`). Live decompile 2026-08-04 ≡ raw scaffold 2026-07-23 CF shape; bytes refine post-delete stores.

Polarity vs family: PushBack/PushFront **allocate** pages; this **releases** them. PopFront is header-only (no free) — sealed contrast.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector storage dtor (unlocked):
//   ECX = container
//     +0x04 pages**, +0x08 capacity (pages), +0x0c begin, +0x10 size
//   size = 0; if was non-empty: begin = 0
//   for each page slot 0..capacity-1: if pages[i] delete pages[i]
//   if pages: delete pages
//   capacity = 0; pages = 0
// Do NOT free the header; do NOT run element dtors.
// Prefer bytes over decompiler for the final zero stores.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/free contract; decompiler gap on post-delete zeros is documented and closed by bytes. Naming residual + runtime open → **accept-with-gaps**.
