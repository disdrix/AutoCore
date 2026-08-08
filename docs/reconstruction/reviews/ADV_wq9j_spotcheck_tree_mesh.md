# Independent ADV spot-check — WQ9J tree/mesh/shop (2026-08-04)

| Field | Value |
|---|---|
| Role | Independent adversarial verifier (not dual author) |
| Units | `0x00409160` StdTree_Min_Isnil31; `0x004094c0` StdMap_StringKey_EraseAndRebalance_Inferred; `0x00634c50` MeshHost_UploadXformPosNormAndIB16_Inferred; `0x00833160` ShopVehObject_SwapSelectState_ESI_EDI_Inferred |
| Terminal | **false** |

## Verdicts

| Unit | Dual | ADV |
|---|---|---|
| `0x00409160` StdTree_Min_Isnil31 | accept | **PASS** |
| `0x004094c0` StdMap_StringKey_EraseAndRebalance_Inferred | accept-with-gaps | **PASS** |
| `0x00634c50` MeshHost_UploadXformPosNormAndIB16_Inferred | accept-with-gaps | **PASS-WITH-FINDINGS** |
| `0x00833160` ShopVehObject_SwapSelectState_ESI_EDI_Inferred | accept-with-gaps | **PASS** |

## Independent checks

- Dual A/B + dual report + named cleans + raw re-verify present for all four.
- Tree min: EAX node leaf isnil@+0x31; peer isnil29 different ABI — non-merge holds.
- StringKey erase: isnil@+0x2d color@+0x2c RET 0x0C; sole erase-range caller — non-merge from isnil29 erase holds.
- MeshHost: fastcall ECX host; FieldBlock via dualed `00416240`; VB/IB lock strings sealed; product English residual.
- ShopVeh swap: ESI/EDI register pair; nested xform via dualed FieldBlock helpers; sole reindex caller.

## Soft findings

- MeshHost dirty-flag English open; FVF usage enum residual.
- No CF rejects; no dual rewrites; no parent ledger edits.

**Overall: PASS-WITH-FINDINGS** · terminal false
