# Review A (reconstruction fidelity): `aa_004cb3e0` CVOGObject_StoreLocalPosition4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb3e0` |
| **VA** | `0x004cb3e0` |
| **Body span** | `004cb3e0` – `004cb409` (**42** bytes / `0x2a`; exclusive end `004cb40a`) |
| **Canonical name** | `FUN_004cb3e0` (Ghidra) |
| **Proposed name** | `CVOGObject_StoreLocalPosition4_Inferred` (**Probable** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb3e0` — **misleading** (parent trap string; this leaf only stores) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_004cb3e0_CVOGObject_StoreLocalPosition4_Inferred.md` |
| **Scratch** | `reviews/a_004cb3e0.md` |
| **System** | object pose / local position override (`+0x240` block); used by gated writer + bypass |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Unconditional leaf store** of a **4×float (vec4 / float4)** into **`this+0x240..+0x24c`**.

No NaN trap, no component-flag gate, no callees. Callers that need gating own that logic (notably `FUN_004c3a40`); this unit is the pure memory write half of local-position override.

**Calling convention:** MSVC `__thiscall` — object in **ECX**, `float*` / `uint32_t*` on stack, **`ret 4`**.

**Not** thr/steer/HB / not a physics apply / not a getter.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cb3e0_FUN_004cb3e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb3e0_FUN_004cb3e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004cb3e0.cpp` |
| Named scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb3e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cb3e0_FUN_004cb3e0.md` |
| Live decompile | Ghidra `decompile_function` @ `0x004cb3e0` |
| Live bytes | `read_memory` @ `0x004cb3e0` length 64 |
| Function meta | `get_function_by_address` → body `004cb3e0`–`004cb409` |
| Live xrefs | `get_function_xrefs` / `get_function_callers` → **2** sites / **2** functions |
| Parent dual (context only) | `A/B_aa_004c3a40_CVOGObject_SetLocalPosition4_Gated_Inferred.md` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, deep dual of callers `004c3a40` / `005cd3b0` (caller inventory only), ledger updates.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `004cb3e0`–`004cb409` (42 B, ends `ret 4`) | **High** | Ghidra body range + `read_memory` |
| Thiscall ECX=`this`, stack=`dword*` / float* | **High** | `mov eax,[esp+4]`; stores via `ecx+disp`; `ret 4` |
| Stores exactly four dwords: `+0x240,+0x244,+0x248,+0x24c` | **High** | Imm displ in every `mov [ecx+…]` |
| Order: in[0]→+0x240 … in[3]→+0x24c | **High** | Sequential load/store |
| No branches / no callees / no NaN / no gate | **High** | Straight-line only |
| W (`in[3]`) always written | **High** | Fourth store present |
| ABI pops **4** stack bytes (`c2 04 00`) | **High** | Not plain `c3` |
| Callers: `FUN_004c3a40` @ `004c3aa6`, `FUN_005cd3b0` @ `005ce8a3` | **High** | Live xrefs |
| Payload is “local position override” block | **Probable** | Parent dual + sibling getter `004c3ac0` prefer `+0x240`; no RTTI here |
| Product English method name | **Open / Tentative** | Keep `_Inferred` / `FUN_*` |
| Exhaustive **readers** of `+0x240` | **Out of OWN scope** | Not this VA’s body |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ instructions

| Stage | Match |
|---|---|
| Load stack arg into EAX | **Yes** (`mov eax,[esp+4]`) |
| Copy dword0 → `this+0x240` | **Yes** |
| Copy dword1 → `this+0x244` | **Yes** |
| Copy dword2 → `this+0x248` | **Yes** |
| Copy dword3 → `this+0x24c` | **Yes** |
| `ret 4` | **Yes** |
| No invent gates / traps / clamps | **Yes** |

### 4.1 Pseudocode (sealed)

```c
// __thiscall  ECX=object,  stack: const uint32_t *in  (float[4] as dwords)
void CVOGObject_StoreLocalPosition4_Inferred(Object *self, const uint32_t *in)
{
    *(uint32_t *)((uint8_t *)self + 0x240) = in[0];
    *(uint32_t *)((uint8_t *)self + 0x244) = in[1];
    *(uint32_t *)((uint8_t *)self + 0x248) = in[2];
    *(uint32_t *)((uint8_t *)self + 0x24c) = in[3];
}
```

### 4.2 Machine bytes (`read_memory` @ `0x004cb3e0`)

```
8b 44 24 04          mov eax, [esp+4]        ; in
8b 10                mov edx, [eax]
89 91 40 02 00 00    mov [ecx+0x240], edx
8b 50 04             mov edx, [eax+4]
89 91 44 02 00 00    mov [ecx+0x244], edx
8b 50 08             mov edx, [eax+8]
89 91 48 02 00 00    mov [ecx+0x248], edx
8b 40 0c             mov eax, [eax+0xc]
89 81 4c 02 00 00    mov [ecx+0x24c], eax
c2 04 00             ret 4
; then cc padding (outside body)
```

### 4.3 Live decompile (2026-07-29)

```c
void __thiscall FUN_004cb3e0(int param_1, undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 0x240) = *param_2;
  *(undefined4 *)(param_1 + 0x244) = param_2[1];
  *(undefined4 *)(param_1 + 0x248) = param_2[2];
  *(undefined4 *)(param_1 + 0x24c) = param_2[3];
  return;
}
```

≡ frozen raw `docs/reconstruction/raw/aa_004cb3e0_FUN_004cb3e0.md`.

---

## 5. Callers (own VA xrefs only)

| Function | Call site | Role (caller CF — not dualed here) |
|----------|-----------|-------------------------------------|
| `FUN_004c3a40` | `0x004c3aa6` | Gated SetLocalPosition4: NaN xyz trap then `0xC7` gate; **this** is the store on allow |
| `FUN_005cd3b0` | `0x005ce8a3` | Bypass / ungated path into the same leaf |

**2** `UNCONDITIONAL_CALL` sites / **2** caller functions. Leaf is **not** exclusive to the gated parent.

---

## 6. Gaps / open

1. Product method name / RTTI (remain `_Inferred`).
2. Semantic certainty that the four floats are always “position + W” vs generic vec4 (consumers treat as local pos override — **Probable** from parent dual / getter; not proven inside this body).
3. Deep dual of `FUN_005cd3b0` bypass writer (out of OWN scope).
4. Runtime / differential store under live objects.
5. Full reader inventory of `+0x240` (sibling getter `004c3ac0` known from parent dual only).
6. Optional Ghidra rename to proposed name.

**Verdict:** **accept-with-gaps** — machine body, ABI, four-offset layout, and **2**-site caller inventory sealed static; product name / full consumer graph / runtime remain open. Package **not complete**.
