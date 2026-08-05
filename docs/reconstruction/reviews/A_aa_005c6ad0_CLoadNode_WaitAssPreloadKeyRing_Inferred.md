# Review A (reconstruction fidelity): `aa_005c6ad0` CLoadNode_WaitAssPreloadKeyRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6ad0` |
| **VA** | `0x005c6ad0`–`0x005c6b3e` exclusive (**110 B**) |
| **Canonical name** | `CLoadNode_WaitAssPreloadKeyRing_Inferred` |
| **Ghidra name** | `FUN_005c6ad0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-F) |
| **Counterpart** | `reviews/B_aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md` |
| **System** | CLoadNode stage coop-wait + AssPreloader |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + full-body `read_memory` (110 B) + callers + caller decompile `005c72f0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

One cooperative wait tick for a CLoadNode stage key ring: optional ExpandDeps when counter outside 1..6, then ProcessKeyRingStep; return 3 (wait) or 0 (ready).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-F append) | `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode_WaitAssPreloadKeyRing_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005c6ad0.cpp` |
| Sealed callees | W35-A `004ed310`; W32-K `00971820` |
| Callers | five CLoadNode stage fns / 6 xrefs |

---

## 3. Signature (sealed)

```c
// ECX=host, stack ring*; RET 0x4; EAX 0/3
uint32_t CLoadNode_WaitAssPreloadKeyRing_Inferred(void* host, void* ring);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX → ESI; +0x54 counter, +0x5c cursor | **High** |
| ring | stack → EDI; size@+0x10 | **High** |
| return | EAX 0 / 3 | **High** |

Caller seal (`005c72f0`): `MOV ECX,EDI` (node this); `PUSH` clonebase ring; `CALL`; `CMP EAX,3`.

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty ring → counter=0, return 0 | `CMP [EDI+10],0` / `JBE` | **High** |
| Counter not in 1..6 → maybe reset + ExpandDeps | bytes + decompile | **High** |
| ExpandDeps ECX=AssPreloader | `MOV EAX,[DAT]; MOV ECX,[EAX+6C]; PUSH EDI` | **High** |
| flag=1; ProcessKeyRingStep cdecl | pushes + `ADD ESP,0C` | **High** |
| yield → counter++, EAX=3 | `MOV EAX,3; RET 4` | **High** |
| ready → counter=0, EAX=0 | `XOR EAX,EAX; RET 4` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 110 B hex in raw W36-F append. Both exits **`C2 04 00`**.

---

## 6. Gaps

- Product/PDB method English on CLoadNode.
- Exact product meaning of counter band 1..6 (retry budget sealed structurally).
- Runtime / concurrent AssPreloader mutation — open.

---

## 7. Verdict

Fidelity pass seals small-body ABI/CF/returns and CLoadNode parent pattern. Residuals product English → **accept-with-gaps**.
