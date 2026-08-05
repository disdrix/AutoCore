# Review A (reconstruction fidelity): `aa_0040c720` UiToastQueue_InsertGrow

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c720` |
| **VA** | `0x0040c720` |
| **Canonical name** | `UiToastQueue_InsertGrow` (structural; product/PDB open) |
| **Ghidra name** | `FUN_0040c720` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0040c720_UiToastQueue_InsertGrow.md` |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Verdict** | **accept** on CF / stride / thiscall wiring / grow→insert callee; product name **open** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Grow-path insert helper** for the UI toast vector of stride **`0x98`**.

When `Client_UiToastQueue_Push` @ `0x0040c5c0` finds the queue empty or full (`size >= capacity`), it calls this unit with:

- **ECX** = toast queue (`this`)
- **out iterator*** (stack)
- **insert position** = current `end` pointer (append)
- **element value** (POD toast blob / reference used by insert)

Body:

1. Compute insert **index** = `(pos − begin) / 0x98` when `begin != 0` and size ≠ 0; else **0**.
2. `FUN_00403980(pos, 1, element)` — thiscall **insert N=1** (may realloc / 1.5× grow).
3. Write `*outIt = begin + index * 0x98` (iterator to inserted / stable slot after grow).

Does **not** format toast text, grant missions, or bump end without going through `00403980`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0040c720_FUN_0040c720.md` |
| Raw / annotated / clean | `raw/aa_0040c720_*`, `reconstructed-exact/FUN_0040c720.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x0040c720` (2026-07-29) |
| Live body bytes | Ghidra `read_memory` `0x0040c720` length 100 |
| Sole caller (static) | `FUN_0040c5c0` / `Client_UiToastQueue_Push` |
| Insert callee | `FUN_00403980` (vector insert-N for stride `0x98`) |
| Parent dual | `reviews/A_aa_0040c5c0_Client_UiToastQueue_Push.md` |

**Not performed:** Launcher, runtime, bit-exact, dual of `00403980` internals beyond CF summary (separate unit in this batch).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX = queue | **Confirmed** | `mov edi, ecx`; parent `mov ecx, esi` before call |
| Stride **`0x98`** for size/index | **Confirmed** | magic imul `0x6bca1af3` + sar pattern; `index*0x98` via `×19×8` LEA |
| Index 0 when begin null or size 0 | **Confirmed** | decompile + branch to `xor` path |
| Always insert **count = 1** | **Confirmed** | `push 1` before `call 00403980` |
| Out-iterator write `*param_2 = begin + idx*0x98` | **Confirmed** | post-call arithmetic |
| Role = toast grow/insert bridge (not push itself) | **High** | sole caller is push grow branch |
| Parent decompiler sometimes elides `this` | **Confirmed artifact** | see B / parent dual claim 8 |
| Product symbol | **Open** | structural |
| Clean ≡ raw ≡ live CF | **Confirmed** | scaffold types only |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load begin `*(this+4)` | **Yes** |
| If begin && size≠0 → idx = (pos−begin)/0x98 | **Yes** |
| Else idx = 0 | **Yes** |
| `FUN_00403980(pos, 1, element)` thiscall | **Yes** |
| `*out = begin + idx*0x98` | **Yes** |
| No toast formatting | **Yes** |

### Recovered CF

```c
// __thiscall
void UiToastQueue_InsertGrow(ToastQueue *this, void **outIt, void *pos, /*element*/ void *elem)
{
    int begin = *(int *)(this + 4);
    int idx = 0;
    if (begin != 0) {
        int size = (*(int *)(this + 8) - begin) / 0x98;
        if (size != 0)
            idx = ((int)pos - begin) / 0x98;
    }
    FUN_00403980(/*this*/ this, pos, /*count*/ 1, elem);
    *outIt = (void *)(*(int *)(this + 4) + idx * 0x98);
}
```

---

## 5. Assembly notes (from `read_memory`)

Entry / this capture:

```
0040c720  53              push ebx
0040c721  8b5c240c        mov  ebx, [esp+0xc]   ; pos (after 1 push)
0040c725  56              push esi
0040c726  57              push edi
0040c727  8bf9            mov  edi, ecx         ; this
0040c729  8b7704          mov  esi, [edi+4]     ; begin
…
; size via signed /0x98 magic (0x6BCA1AF3)
; then: push element; push 1; push pos; mov ecx,edi; call FUN_00403980
; then: begin' = [edi+4]; out = begin' + idx*0x98
```

Divide-by-`0x98` magic matches parent push body. Index×`0x98` reconstructed as `(idx*19)<<3` LEA chain (19×8=152).

---

## 6. Gaps

1. Product / PDB name for insert-grow helper.
2. Exact C++ signature of `FUN_00403980` formals (insert-at-iterator vs pointer) — sealed in sibling dual.
3. Whether any other static caller appears under different image builds — this image: sole `0040c5c0`.

**Verdict:** **accept** — sealed grow-bridge CF, stride, thiscall, insert-1, out-iterator write.
