# Review A (reconstruction fidelity): `aa_005cc7c0` EntityHost_ApplyNestedLocalPosition_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc7c0` |
| **VA** | `0x005cc7c0` |
| **Body span** | `005cc7c0` – `005cc7e7` (**40** bytes) |
| **Canonical name** | `FUN_005cc7c0` (Ghidra) |
| **Proposed name** | `EntityHost_ApplyNestedLocalPosition_Inferred` (**Probable**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W23-J) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ instructions) |
| **Counterpart** | `reviews/B_aa_005cc7c0_EntityHost_ApplyNestedLocalPosition_Inferred.md` |
| **System** | `input-drive-control` / object pose |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Short **host virtual** that forwards a **local float4** onto the nested CVOG-like object at **`host+0x64`**, after a physics/body prep call and a **dirty-byte** set:

1. `FUN_0053d970(*(host+0x64), 0)` — prep (stack formal forced 0).
2. `*(u8*)(*(host+0x64) + 0x304) = 1` — dirty / needs-recompute.
3. `FUN_004c3a40(*(host+0x64), vec)` — gated store into nested `+0x240..+0x24c`.

**Calling convention:** MSVC `__thiscall` — host in **ECX**, **two** stack dwords cleaned (`ret 8`); body uses **only** the first as `float*`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005cc7c0_FUN_005cc7c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005cc7c0_FUN_005cc7c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005cc7c0.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/EntityHost_ApplyNestedLocalPosition_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_005cc7c0_FUN_005cc7c0.md` |
| Gated set-pos (sealed sibling) | `FUN_004c3a40` / `aa_004c3a40` |
| Prep callee | `FUN_0053d970` @ `0x0053d970` (`read_memory` epilogue `ret 4`) |

**This pass (live):** Ghidra `decompile_function` @ `0x005cc7c0` + `0x0053d970` + `0x004c3a40` (context); `read_memory` body + callee epilogue + five DATA xref slots; `get_function_by_address` / callees / xrefs / callers. **Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `005cc7c0`–`005cc7e7` (40 B), `ret 8` | **High** | `read_memory` through `c2 08 00` + `cc` pad |
| Thiscall ECX=host → ESI | **High** | `mov esi,ecx` |
| Nested object `*(host+0x64)` | **High** | three loads of `[esi+0x64]` |
| Prep: `push 0; call FUN_0053d970` thiscall on nested | **High** | bytes + callee `ret 4` |
| Dirty: **byte** store `1` at nested `+0x304` | **High** | `c6 80 04 03 00 00 01` |
| Set-pos: `FUN_004c3a40` thiscall on nested with stack vec | **High** | push + `mov ecx,[esi+0x64]` + call |
| Stack arg2 unread | **High** | no load of `[esp+0xc]` path; still cleaned |
| Five DATA vtable slots | **High** | xrefs + dword `c0 c7 5c 00` at each |
| No direct CALL xrefs | **High** | callers empty; virtual dispatch only |
| Product English host/method name | **Tentative** | `_Inferred` |
| Arg2 semantic | **Open** | interface width only |
| Null-safety of `*(host+0x64)` | **Open** | no null check in body |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ instructions

| Stage | Match |
|---|---|
| Save ESI; host→ESI | **Yes** |
| ECX=nested; push 0; call `0053d970` | **Yes** |
| Reload nested; load stack arg1 as vec | **Yes** |
| `mov byte [nested+0x304],1` | **Yes** |
| push vec; ECX=nested; call `004c3a40` | **Yes** |
| pop ESI; `ret 8` | **Yes** |
| No thr/steer / no extra stores | **Yes** |

### 4.1 Pseudocode (sealed)

```c
// __thiscall  ECX=host;  stack: float *vec,  /*unread*/ arg2;  ret 8
void EntityHost_ApplyNestedLocalPosition_Inferred(void *host, float *vec, void *arg2)
{
    (void)arg2;
    void *object = *(void **)((char *)host + 0x64);
    FUN_0053d970(object, 0);
    *(uint8_t *)((char *)object + 0x304) = 1;
    FUN_004c3a40(object, vec);
}
```

### 4.2 Linkage to sealed set-pos (`aa_004c3a40`)

| Step here | Sibling effect |
|-----------|----------------|
| Dirty `+0x304=1` **before** set-pos | DCT path sets dirty **after** set-pos — order differs; flag same |
| Vec → `FUN_004c3a40` | NaN xyz trap + gate `0xC7` @ typeOff+0xb8 + store `+0x240..24c` |

---

## 5. Dispatch (live xrefs 2026-07-29)

| Address | Kind | Value |
|---------|------|-------|
| `0x009da9d0` | DATA | `0x005cc7c0` |
| `0x009daf58` | DATA | `0x005cc7c0` |
| `0x009db0d8` | DATA | `0x005cc7c0` |
| `0x009db138` | DATA | `0x005cc7c0` |
| `0x009db198` | DATA | `0x005cc7c0` |

**0** `UNCONDITIONAL_CALL` sites — pure vtable install.

---

## 6. Gaps / open

1. Product / RTTI host class and slot English name (remain `_Inferred`).
2. Meaning of unread second stack arg (width sealed only).
3. Which host types share the five vtables; slot index inventory.
4. Full producer/consumer set for nested `+0x304`.
5. Runtime / differential (null nested, NaN vec, gate closed).
6. Deep dual of `FUN_0053d970` / `FUN_005d4440` (out of OWN scope; callee bytes only for contract).

**Verdict:** **accept-with-gaps** — ABI (`ret 8`), nested `+0x64`, dirty `+0x304` byte, call order, vtable-only dispatch, and linkage to sealed set-pos **High**; product name / arg2 / runtime open.
