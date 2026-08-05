# Review A (reconstruction fidelity): `aa_005bbc50` ObjectMotion_HostTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbc50` |
| **VA** | `0x005bbc50`–`0x005bbd96` exclusive (Ghidra); true `c3` ≈ `0x005bbdc0` |
| **Body** | **326** B Ghidra / `0x146` (+ SEH tail to `c3`) |
| **Canonical name** | `ObjectMotion_HostTeardown_Inferred` |
| **Ghidra name** | `FUN_005bbc50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-S) |
| **Counterpart** | `reviews/B_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md` |
| **System** | client object motion / reaction host teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + callers/callees + call-site freelist bytes |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tear down a motion/FX **host** object before recycle/free:

1. Clear/free primary buffer (`+0x308` vs inline `+0x14`) via `FUN_005b8340` + `operator_delete`.
2. If `+0x7fc`: clear/free secondary buffer (`+0x6ec` vs inline `+0x3f8`).
3. Walk list `+0xa24`; freelist-release each payload at node`[+0x8]` via `ObjectMotion_SlotReleaseToFreelist_Inferred` with **`ECX = DAT_00b036c0`**.
4. Empty list nodes, free sentinel, null `+0xa24` / count `+0xa28`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | full body @ `0x005bbc50` |
| Bounds | `get_function_by_address` → `005bbc50`–`005bbd96` |
| Entry bytes | SEH prolog `6a ff 68 ad 6b 9a 00 …` |
| Exit bytes | SEH unlink + **`c3`** @ ~`0x005bbdc0` (`read_memory`) |
| Slot call site | `50 B9 C0 36 B0 00 E8 …` (`push`; `mov ecx,0xB036C0`; call) |
| Caller | `FUN_005be310` decompile + bytes (`ret 4` wrapper) |
| Callee sealed | `ObjectMotion_SlotReleaseToFreelist_Inferred` (W28-I) |
| Raw / annotated / clean | W30-S updated |

**Not performed:** Launcher, runtime golden, product demangle, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = host*; no stack args; ret (c3); void
void ObjectMotion_HostTeardown_Inferred(void *host);
```

| Formal | Source | Conf |
|---|---|---|
| this / ECX | host object | **High** |
| stack args | none | **High** |
| cleanup | plain `ret` (`c3`) after SEH | **High** (`read_memory`) |
| return | void | **High** |

---

## 4. Control flow checklist

| Stage | Match | Conf |
|---|---|---|
| SEH prolog | **Yes** | **High** |
| Primary buffer free if heap | **Yes** | **High** |
| Secondary buffer gated by `+0x7fc` | **Yes** | **High** |
| Slot list walk + freelist release | **Yes** | **High** |
| Global freelist ECX | **Yes** | **Confirmed** |
| List empty + sentinel delete | **Yes** (decomp partial; bytes loop) | **High** |
| Final `c3` | **Yes** | **Confirmed** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = host content teardown | **High** | buffers + slot freelist + list free |
| Freelist head global | **Confirmed** | site bytes |
| Ghidra body truncated by noreturn delete | **Confirmed** | tail `c3` outside listed end |
| List free is full walk not single node | **High** | `75 eb` back-edge in bytes |
| Product English | **Inferred** | `_Inferred` |
| Exact `FUN_005b8340` ECX targets | **Medium** | not OWN; multiple calls |
| Runtime | **Open** | |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Exact buffer header layouts for `FUN_005b8340` ECX.
3. Decompiler double-reset of `+0xa24` vs bytes free-loop — staged clean uses walk-all.
4. Relationship of host type to emitter vs generic motion host (shared layout with `+0xa24`).
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — ABI + role + freelist walk sealed; buffer typing and noreturn tail residual.
