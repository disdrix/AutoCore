# Review B (skeptical / adversarial): `aa_004ac100` MapChild_RebuildHostElemsAndIntGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ac100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-L) |
| **Counterpart** | `reviews/A_aa_004ac100_MapChild_RebuildHostElemsAndIntGrid_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Method name is VOG_DEBUG_STOP | **Falsified** — string only on fail guard; success path is full rebuild; same string used by host rebuild peer |
| 2 | This **is** `FUN_004941b0` / host rebuild | **Falsified** — outer orchestrator; also builds int grid and calls follow-ups; host rebuild is callee with distinct ABI |
| 3 | Decompile call `FUN_004941b0(*(this+0x340))` is complete | **Falsified** — bytes load host from `*(map+0xe898)` into ECX, push map; W30-Q caller ABI |
| 4 | cdecl / no stack cleanup | **Falsified** — all exits `C2 04 00`; callers push a dword |
| 5 | Return is void | **Falsified** — `xor al,al` fail; `mov al,1` success |
| 6 | Second zero-loop is real work | **Falsified as written** — decompile shows dead `iVar3=0` loop; bytes use `and ecx,3; rep stosb` remainder |
| 7 | `+900` is authoritative offset | **Partial** — decompiler decimal for **`+0x384`**; bytes write `89 86 84 03 00 00` |
| 8 | Multiple independent product systems | **Careful** — callers tie this to map init (`FUN_004d9cd0` creates 0x3fc child, stores at map+0xe4f8) and grid clear (`FUN_004ac220`); product English still open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Orchestrator vs host-rebuild identity | **High** | Double-port / wrong layer |
| ABI ret 4 + unused stack | **High** | Stack imbalance |
| Host ECX load | **High** | Call on wrong object |
| Dim formula + grid size | **High** | Wrong allocation |
| Follow-up helper English | **Low** | Naming / over-port |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Caller FUN_004ac220:
push 0; mov ecx, esi; call FUN_004ac100

// Caller FUN_004d9cd0 (map parent):
// allocates child 0x3fc, *(child+0x340)=map, map[+0xe4f8]=child
mov ecx, [esi+0xe4f8]; …; call FUN_004ac100

// Own host rebuild setup:
mov eax, [esi+0x340]
mov ecx, [eax+0xe898]
push eax
call FUN_004941b0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF stages. Bytes supersede decompiler on host load, ret 4, remainder zero, and offset `0x384`.

---

## 4. Surviving contract for AutoCore

```
// Port as map-child orchestrator (not host rebuild, not VOG plate):
uint8_t MapChild_RebuildHostElemsAndIntGrid_Inferred(void* self, int /*unused*/) {
  if (!*(self+0x3d8)) { debug_stop("VOG_DEBUG_STOP"); return 0; }
  map = *(self+0x340); host = *(map+0xe898);
  Host_RebuildElem0x28ArrayFromMap(host, map);
  dimX/Y = signed_div16(self+0x10/+0x14) → +0x384/+0x388;
  replace zeroed int grid at +0x38c (dimX*dimY dwords);
  follow-ups; return 1;
}
// Preserve thiscall + ret 4. Reject Named_VOG_DEBUG_STOP.
// Do not merge with FUN_004941b0 body.
```

---

## 5. Verdict

Adversarial pass confirms A on identity/ABI/host call/dims/grid. Residual product English and non-OWN follow-ups → **accept-with-gaps**.
