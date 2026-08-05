# Dual A/B report — W18-E OWN `aa_00436650` + `aa_0043f210`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00436650`, `0x0043f210`. Dual A/B + artifacts.  
**Agent:** W18-E  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Verdict |
|------|---------|
| `aa_00436650` CircularPtrBuf_Grow | **accept-with-gaps** — circular pointer-map grow sealed (EBX this, geometric grow, bytes fix for post-delete commit) |
| `aa_0043f210` Math_Matrix4x4_Set16 | **accept** — **208-byte** thiscall 16-float matrix materialize sealed (`ret 0x40`) |

---

## Sealed facts — `aa_00436650` (0x00436650)

1. **ABI:** custom — **`this` in EBX**, `uint grow_request` on stack, **`ret 4`**. Not ECX thiscall.

2. **Body:** `0x00436650`–`0x00436794` (**324 bytes**); last insn `ret 4` @ `0x00436791`.

3. **Layout:** `+0x04` slots**, `+0x08` capacity, `+0x0C` head (`+0x10` count untouched).

4. **Algorithm:** max-size guard (`0xCCCCCCC` → throw `"deque<T> too long"` via `FUN_00436860`); geometric grow `max(req, max(cap/2, 8))`; `operator_new((cap+grow)*4)`; circular `memmove` rearrange + zero new slots; `operator_delete(old)` if non-null; **`capacity += grow; slots = new`**.

5. **Decompiler bug sealed:** plate marks `operator_delete` noreturn and omits commit — **bytes fall through** to capacity/slots publish.

6. **Name:** `CircularPtrBuf_Grow` — role-sealed **INFERRED** (family with `aa_00436340`). Ghidra: `FUN_00436650`.

7. **Callers:** sole — `FUN_00436340` @ `0x00436350` (`push 1`).

### Gaps (`00436650`)

1. Product/PDB container name.  
2. Full algebra residual on every memmove length (CF sealed).  
3. Runtime / bit-exact / differential — open.

---

## Sealed facts — `aa_0043f210` (0x0043f210)

1. **ABI:** `__thiscall` — **`float *out` in ECX**, **16 stack floats**, **`ret 0x40`**.

2. **Body:** `0x0043f210`–`0x0043f2df` (**208 bytes**).

3. **Algorithm:** spill 16 stack floats (`movss`) → `rep movsd` ×16 dwords into dest. **Leaf. No math.**

4. **Not** a perspective formula builder — callers (e.g. gfxView `FUN_0075b7f0`) precompute elements. Sibling **`FUN_0043f2e0`** is ortho **math** fill.

5. **Name:** `Math_Matrix4x4_Set16` — role-sealed **INFERRED**. Ghidra: `FUN_0043f210`.

6. **Callers:** `FUN_0075b7f0`, `FUN_004d10d0`, `FUN_004e9570`, `FUN_004f9030`.

### Gaps (`0043f210`)

1. Product/PDB English symbol.  
2. Runtime / bit-exact / differential — open.

---

## Files

### `aa_00436650`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00436650_CircularPtrBuf_Grow.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00436650_CircularPtrBuf_Grow.md` |
| Function record | `docs/reconstruction/functions/aa_00436650_FUN_00436650.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CircularPtrBuf_Grow.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00436650.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_00436650_FUN_00436650.md` |
| Annotated | `docs/reconstruction/raw/aa_00436650_FUN_00436650.annotated.md` |
| Scratch | `tmp/a_00436650.md` |

### `aa_0043f210`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0043f210_Math_Matrix4x4_Set16.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0043f210_Math_Matrix4x4_Set16.md` |
| Function record | `docs/reconstruction/functions/aa_0043f210_FUN_0043f210.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_Matrix4x4_Set16.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_0043f210.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_0043f210_FUN_0043f210.md` |
| Annotated | `docs/reconstruction/raw/aa_0043f210_FUN_0043f210.annotated.md` |
| Scratch | `tmp/a_0043f210.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00436650-0043f210-w18e-report.md` |

---

## AutoCore impact

- **`CircularPtrBuf_Grow`:** client-only container grow; ports can treat as opaque or map to a standard ring/`deque` of pointers. Do **not** omit post-delete capacity publish. Preserve EBX/custom ABI only if hooking retail; server ports use normal C++ this.
- **`Math_Matrix4x4_Set16`:** trivial `float[16]` assign / memcpy. Do **not** implement projection math here — keep formulas at call sites (gfxView-style). Sibling ortho math remains `Math_MatrixOrthoOffCenterLH` (`0x0043f2e0`).
