# Review B (skeptical / adversarial): `stoChunkReader_readF32Array` @ `0x00436090`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436090` |
| **VA** | `0x00436090` |
| **Body span** | `00436090` – `00436127` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_00436090_stoChunkReader_readF32Array.md` |
| **System** | `sto-chunk` / asset serialize |
| **Verdict** | **accept-with-gaps** on OWN CF; **needs-more-evidence** on alt-path callee + bulk helper packaging in clean plate |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | “This” is the chunk reader | **Falsified for ECX** — ECX is **dest**; reader is **stack**. Name `stoChunkReader_*` describes domain, not MSVC thiscall owner. |
| 2 | Count is a normal stack/this parameter | **Falsified** — count is **EAX-only** (`in_EAX`); missing it at call sites mis-sizes reads. |
| 3 | Bulk threshold is `count > 15` vs `>= 16` | **Equivalent** under integer math (`0xf < n` ≡ `n >= 16`); asm uses `cmp eax,10h` / **signed** `jge`. |
| 4 | Clean plate bulk call `FUN_00435f30(dest, count*4)` is complete | **Overstated** — own body pushes `count*4`, `dest`, and sets **ECX = reader+0x14**. Decompiler collapsed the subobject `this`. |
| 5 | Alt path is definitely “byte-swap each f32” | **Overstated** — plate comment only. Call shape is `FUN_00767fd0(reader, dest_elem)`; callee body not owned here; sibling raw looks text/token heavy. |
| 6 | Failed buffer guard still writes 0.0f | **Falsified** — store is conditional; dest pointer still advances → **uninitialized / stale slot** risk for ports that zero-fill. |
| 7 | Always returns success | **Falsified for bulk** — returns `FUN_00435f30` status (can be `0xffffffff` per that helper’s raw). Element paths force **0**. |
| 8 | Runtime verified | **Falsified** — open / deferred. |
| 9 | Three-rep is modernization-safe | **Overstated** — clean is CF scaffold of decompiler; not bit-exact EXE proof. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX count / ECX dest / stack reader / `ret 4` | **High** | Wrong convention → total unserialize corruption |
| Mode `reader+0x4044` | **High** | Binary vs alt mix-up on text assets |
| Bulk at signed `count >= 16` | **High** | Performance path only, but status return differs |
| Bulk `this = reader+0x14` | **High (asm)** | Ports that call free-func memcpy skip refill/vfunc paths in helper |
| Cursor `+0x18`, bound `+0x20`, window `+0x2c` | **High** | Off-by-4 stream desync |
| Soft-fail skip-write on guard fail | **High CF** | Ports that zero dest hide retail garbage-slot behavior |
| Alt `FUN_00767fd0` product meaning | **Low–Medium** | Wrong endian/text assumption breaks non-binary chunks |
| Clean ≡ raw decompiler CF | **High** | Safe as map; unsafe as sealed codec without asm bulk fix |
| Callee bodies | **Out of scope** | Dual OWN-only; do not treat sibling FUN_ names as sealed |

---

## 3. Surviving contract for AutoCore

```
// count: EAX; dest: ECX; reader: stack arg; stdcall-ish ret 4
status = stoChunkReader_readF32Array(dest, reader, count_in_EAX):
  if reader.mode4044 == 0:
    if count >= 16:                    // signed
      return bulk_read(reader+0x14, dest, count*4)   // FUN_00435f30
    if count <= 0: return 0
    for i in 0..count-1:
      if cursor+4 <= avail OR (refill(base+cursor) >= 0 AND avail > 3):
        dest[i] = load_u32_le(window + cursor)       // as f32 bits
        cursor += 4
      // else: dest[i] NOT written
    return 0
  else:
    if count <= 0: return 0
    for i in 0..count-1:
      FUN_00767fd0(reader, &dest[i])                 // semantics residual
    return 0
```

**Port rules that survive adversarial review:**

1. Never invent a third stack arg for count — keep EAX (or an explicit wrapper that loads EAX).
2. Implement soft-fail skip-write on the small binary path if matching retail; or document intentional zero-fill as a deliberate divergence.
3. Surface bulk status; do not assume element-path `0` for large arrays.
4. Leave alt-path as a named hook until `FUN_00767fd0` is dual-owned.

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs `raw/aa_00436090_*.md` | **Match** (plate + body) |
| Clean vs raw CF stages | **Match** scaffold |
| Clean bulk arity vs own asm | **Mismatch residual** (2-arg decomp vs 3-slot asm with `this=+0x14`) |
| Annotated open questions (signature/types) | Still valid; this dual **seals convention** via asm |

---

## 5. Open questions (OWN residual only)

1. Confirm product name for `reader+0x4044` mode (binary vs text/XML chunk stream).
2. Seal `FUN_00767fd0` under its own dual (not this VA).
3. Whether any caller relies on bulk failure (`0xffffffff`) vs ignoring status.
4. Whether small-path guard failure is reachable under well-formed assets (refill always succeeds) — if yes, soft-skip is dead; if no, ports need the skip semantics.

**Verdict:** **accept-with-gaps** on OWN control flow and register/stack contract; **needs-more-evidence** before treating alt-path as endian-swap or before trusting clean’s bulk call packaging as production-ready. Safe behavioral map for AutoCore sto-chunk f32 array reads once bulk `reader+0x14` and soft-skip rules are honored.
